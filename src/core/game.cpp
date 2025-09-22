//
// Created by lukas on 22.09.2025.
//

#include "game.h"

#include <iostream>
#include <memory>

// Initialize player and enemy instances
void game::initializeEntities() {
    playerInstance = std::make_shared<player>();
    enemyInstance = std::make_shared<basicEnemy>();
}

// Update game logic, player and enemy states
void game::Updater() {

    if (!playerInstance || !enemyInstance) {
        std::cout << "ERROR IN GAME UPDATER\n";
        std::cerr << "Failed to create player or enemy instance.\n";
        return;
    }

    enemyInstance->Update(DeltaTime);
    playerInstance->Update(DeltaTime);

    enemyInstance->chasePlayer(getPlayerShape(), DeltaTime);

}

// Return a shared pointer to a player instance
std::shared_ptr<player> game::getPlayerPtr() {
    return playerInstance;
}

// Return a shared pointer to a basic enemy instance
std::shared_ptr<basicEnemy> game::getEnemyPtr() {
    return enemyInstance;
}

// Return a reference to the enemy's shape
sf::Shape &game::getEnemyShape() {
    if (!enemyInstance) {
        throw std::runtime_error("Enemy not initialized");
    }
    auto shape = enemyInstance->getEntityShape();
    if (!shape) {
        throw std::runtime_error("Enemy shape is null");
    }
    return *shape;
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

