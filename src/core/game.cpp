

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
    rendererInstance = std::make_unique<renderer>();
    itemManagerInstance = std::make_unique<itemManager>();

    if (!playerInstance) {
        throw std::runtime_error("Failed to create player instance.");
    }

    rendererInstance->getUIManager().setHolderPlayerForHUD(getPlayerPtr());

    itemManagerInstance->CreateFirstWeaponForPlayer(getPlayerPtr());

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
    rendererInstance->getUIManager().UpdateAllUI(getPlayerPtr(), DeltaTime);

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
                if (enemy->DamageClock.getElapsedTime().asSeconds() >= 0.25f && playerInstance->getEquipment().getWeaponSlot() != nullptr) {
                    enemy->takeDamage(playerInstance->getEquipment().getWeaponSlot()->getDamage());
                    std::cout << "Player deals " << playerInstance->getEquipment().getWeaponSlot()->getDamage() << " damage.\n";
                    enemy->DamageClock.restart();
                    if (enemy->isDead(playerInstance->getInventory())) {
                        std::cout << "Enemy ID: " << entity->getEntityID().toString() << " is dead.\n";
                        size_t index = &entity - &entityList[0];
                        decreaseEnemyFromList(index);
                        break;
                    }
                }
            }
        }
    }

    if (playerInstance->getEquipment().getWeaponSlot() != nullptr && rendererInstance->hasView()) {
        inputManager:: getInstance().isMouseButtonPressed(
            getPlayerShape().getPosition(),
            projectiles,
            rendererInstance->getView());
    }

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

