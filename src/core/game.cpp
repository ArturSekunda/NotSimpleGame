

#include "game.h"
#include "handlers/collisionHandler.h"

#include <iostream>
#include <memory>

#include "managers/UIManager.h"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

#include "managers/inputManager.h"

// Initialize player and enemy instances
void game::initializeEntities() {

    playerInstance = std::make_unique<player>(0);
    UIManagerInstance = std::make_unique<UIManager>();
    itemManagerInstance = std::make_unique<itemManager>();

    if (!playerInstance) {
        throw std::runtime_error("Failed to create player instance.");
    }

    UIManagerInstance->setHolderPlayerForHUD(getPlayerPtr());

    for (int i = 0; i <= 1; i++) {
        auto enemy = std::make_unique<basicEnemy>(i, getPlayerPtr().getLevel());

        itemManagerInstance->CreateWeaponForEnemy(*enemy);
        itemManagerInstance->CreateArmorForEnemy(*enemy);

        addEntityToList(std::move(enemy));
    }

}
// Only to read
const player& game::getPlayerPtr() const {
    return *playerInstance;
}

// To modify player
player& game::getPlayerPtr() {
    return *playerInstance;
}

// Update game logic, player and enemy states
void game::Updater() {

    // Ensure player instance is valid
    if (!playerInstance) return;

    // Update player
    playerInstance->Update(DeltaTime);


    // Update enemy
    for (auto& entity : entityList) {
        if (entity) {
            entity->Update(DeltaTime);
            if (auto* enemy = dynamic_cast<basicEnemy*>(entity.get())) {
                enemy->chasePlayer(getPlayerShape(), DeltaTime);
            }
        }
    }

    // Update UI
    UIManagerInstance->UpdateAllUI(getPlayerPtr(), DeltaTime);

    // Collision Detection
    std::vector<std::string> collidingEnemies = collisionHandler::getInstance()
        .checkAllCollisions(getPlayerShape(), entityList);

    // Handle Collisions
    for (const auto& enemyIDStr: collidingEnemies) {
        //std::cout << "Collision with Enemy ID: " << enemyIDStr << "\n";
    }

    for (const auto& bullet: projectiles) {
        for (const auto& entity : entityList) {
            auto enemy = dynamic_cast<basicEnemy*>(entity.get());
            if (enemy && bullet->getEntityBounds().intersects(entity->getEntityBounds())) {
                //std::cout << "Projectile hit Enemy ID: " << entity->getEntityID().toString() << "\n";
                enemy->setHealth(entity->getHealth()-20);
                if (enemy->isDead(playerInstance->getInventory())) {
                    std::cout << "Enemy ID: " << entity->getEntityID().toString() << " is dead.\n";
                    size_t index = &entity - &entityList[0];
                    decreaseEnemyFromList(index);
                }
            }
        }
    }

    inputManager::getInstance().isMouseButtonPressed(getPlayerShape().getPosition(), projectiles);
    projectileEntity::updateProjectiles(DeltaTime, projectiles);
    projectileEntity::cleanupProjectiles(projectiles);
}

// Remove an enemy from the list by index
void game::decreaseEnemyFromList(size_t index) {
    if (index <= entityList.size() && index != static_cast<size_t>(-1)) {
        entityList.erase(entityList.begin() + index);
    } else {
        std::cerr << "Invalid index for removing enemy: " << index << "\n";
    }
}

// Return a reference to the player's shape
sf::Shape& game::getPlayerShape() {
    if (!playerInstance) {
        throw std::runtime_error("Player not initialized");
    }
    auto shape = playerInstance->getEntityShape();
    if (!shape) {
        throw std::runtime_error("Player shape is null");
    }
    return *shape;
}

void game::render(sf::RenderWindow &window,sf::View& view) {


    // Camera Follow Player
    view.setCenter(getPlayerShape().getPosition());
    window.setView(view);

    renderPlayerAndEnemies(window);

    projectileEntity::drawProjectiles(window, projectiles);

    if (DeveloperMode) {
        renderDebug(window);
    }


}

void game::renderDebug(sf::RenderWindow &window) {

    if (UIManagerInstance->getDebugWindow() != nullptr){
        if (UIManagerInstance->getWantToShowCollisionBoxes()) {
             collisionHandler::getInstance().render(window, getPlayerCollisionBox(), entityList, getPlayerShape());
                collisionHandler::getInstance().renderProjectileCollisionBox(window, projectiles);
        }
    }


}

void game::renderPlayerAndEnemies(sf::RenderWindow& window) const {
    // Render player
    if (playerInstance && playerInstance->getEntityShape()) {
        window.draw(*playerInstance->getEntityShape());
    }

    // Render enemies
    for (const auto& entity : entityList) {
        if (entity && entity->getEntityShape()) {
            window.draw(*entity->getEntityShape());
        }
    }
}

void game::renderUI(tgui::Gui &gui) {
    UIManagerInstance->RenderMainGameHUD(gui, getPlayerPtr(), DeveloperMode);

}

