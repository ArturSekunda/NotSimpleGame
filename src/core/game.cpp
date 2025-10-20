

#include "game.h"
#include "handlers/collisionHandler.h"

#include <iostream>
#include <memory>

#include "handlers/debugHandler.h"
#include "managers/UIManager.h"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

// Initialize player and enemy instances
void game::initializeEntities() {

    playerInstance = std::make_unique<player>(0);
    UIManagerInstance = std::make_unique<UIManager>();
    itemManagerInstance = std::make_unique<itemManager>();

    if (!playerInstance) {
        throw std::runtime_error("Failed to create player instance.");
    }

    for (int i = 0; i <= 2; i++) {
        itemManagerInstance->CreateItem(getPlayerPtr()->getLevel(),i);
    }

     for (int i = 0; i <= 3; i++) {
         addEntityToList(std::make_unique<basicEnemy>(i));
    }

}
// Only to read
const player * game::getPlayerPtr() const {
    return playerInstance.get();
}

// To modify player
player* game::getPlayerPtr() {
    return playerInstance.get();
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

    // Collision Detection
    std::vector<std::string> collidingEnemies = collisionHandler::getInstance()
        .checkAllCollisions(getPlayerShape(), entityList);

    // Handle Collisions
    for (std::string_view enemyIndex : collidingEnemies) {
        //std::cout << "Collision with enemy " << enemyIndex << "!\n";

    }
    // Update UI
    UIManagerInstance->UpdateAllUI(*getPlayerPtr(), DeltaTime);
}

// Remove an enemy from the list by index
void game::decreaseEnemyFromList(size_t index) {
    if (index < entityList.size() && index != static_cast<size_t>(-1)) {
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
    if (DeveloperMode) {
        renderDebug(window);
    }


}

void game::renderDebug(sf::RenderWindow &window) {

    if (UIManagerInstance->getDebugWindow() != nullptr){
        if (UIManagerInstance->getWantToShowCollisionBoxes()) {
             collisionHandler::getInstance().render(window, getPlayerCollisionBox(), entityList, getPlayerShape());
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
    UIManagerInstance->RenderMainGameHUD(gui, *getPlayerPtr(), DeveloperMode);

}

