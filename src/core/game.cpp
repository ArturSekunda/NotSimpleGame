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

    playerInstance = std::make_shared<player>();

    basicEnemies.push_back(std::make_shared<basicEnemy>());
    basicEnemies.push_back(std::make_shared<basicEnemy>());

    if (basicEnemies.empty()) {
        addEnemyToList(basicEnemies.front());
    }

}

// Update game logic, player and enemy states
void game::Updater() {

    // Ensure player instance is valid
    if (!playerInstance) return;

    // Update Player
    playerInstance->Update(DeltaTime);


    // Update Enemies
    for (auto& enemy : basicEnemies) {
        if (enemy) {
            enemy->Update(DeltaTime);
            enemy->chasePlayer(getPlayerShape(), DeltaTime);
        }
    }

    // Collision Detection
    std::vector<int> collidingEnemies = collisionHandler::getInstance()
        .checkAllCollisions(getPlayerShape(), basicEnemies);

    // Handle Collisions
    for (int enemyIndex : collidingEnemies) {
        std::cout << "Collision with enemy " << enemyIndex << "!\n";

    }
}

// Return a shared pointer to a player instance
std::shared_ptr<player> game::getPlayerPtr() {
    return playerInstance;
}

// Return a shared pointer to a basic enemy instance
std::vector<std::shared_ptr<basicEnemy>> game::getEnemyPtrTable() {
    return basicEnemies;
}
// Remove an enemy from the list by index
void game::decreaseEnemyFromList(size_t index) {
    if (index < basicEnemies.size() && index != static_cast<size_t>(-1)) {
        basicEnemies.erase(basicEnemies.begin() + index);
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

    for (const auto& enemy : basicEnemies) {
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
        for (const auto& enemy : basicEnemies) {
            if (enemy && enemy->getCollisionBox()) {
                auto& enemyBox = *enemy->getCollisionBox();
                enemyBox.setPosition(enemy->getEntityShape()->getPosition());
                window.draw(enemyBox);
            }
        }
    }
}

