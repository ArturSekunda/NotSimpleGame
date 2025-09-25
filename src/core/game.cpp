//
// Created by lukas on 22.09.2025.
//

#include "game.h"
#include "handlers/collisionHandler.h"

#include <iostream>
#include <memory>

#include "handlers/debugHandler.h"

// Initialize player and enemy instances
void game::initializeEntities() {

    playerInstance = std::make_shared<player>(0);

    for (int i = 0; i <= 3; i++) {
        addEntityToList(std::make_shared<basicEnemy>(i));
    }


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
            if (auto enemy = std::dynamic_pointer_cast<basicEnemy>(entity)) {

                enemy->chasePlayer(getPlayerShape(),DeltaTime);
            }
        }
    }

    // Collision Detection
    std::vector<std::string> collidingEnemies = collisionHandler::getInstance()
        .checkAllCollisions(getPlayerShape(), entityList);

    // Handle Collisions
    for (std::string_view enemyIndex : collidingEnemies) {
        std::cout << "Collision with enemy " << enemyIndex << "!\n";

    }
}

// Return a shared pointer to a player instance
std::shared_ptr<player> game::getPlayerPtr() {
    return playerInstance;
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

void game::render(sf::RenderWindow &window, sf::View view) {

    // Camera Follow Player
    if (getPlayerPtr()->getIsMoving()) {
        view.setCenter(getPlayerShape().getPosition());
        window.setView(view);
    }
    renderPlayerAndEnemies(window);
    renderDebug(window);
}

void game::renderDebug(sf::RenderWindow &window) {

    DebugBoxes(window);

}

void game::renderPlayerAndEnemies(sf::RenderWindow &window) const {
    if (playerInstance && playerInstance->getEntityShape()) {
        window.draw(*playerInstance->getEntityShape());
    }

    for (const auto& enemy : entityList) {
        if (enemy && enemy->getEntityShape()) {
            window.draw(*enemy->getEntityShape());
        }
    }
}

void game::DebugBoxes(sf::RenderWindow& window) {
    if (debugHandler::getInstance().getWantToShowCollisionBoxes()) {

        // Collision box for player
        auto playerBox = getPlayerCollisionBox();
        playerBox.setPosition(getPlayerShape().getPosition());
        window.draw(playerBox);

        // Collision boxes for enemies
        for (const auto& enemy : entityList) {
            if (enemy && enemy->getCollisionBox()) {
                auto& enemyBox = *enemy->getCollisionBox();
                enemyBox.setPosition(enemy->getEntityShape()->getPosition());
                window.draw(enemyBox);
            }
        }
    }
}

