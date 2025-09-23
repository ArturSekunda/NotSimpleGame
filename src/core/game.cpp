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

    if (!basicEnemies.empty()) {
        addEnemyToList(basicEnemies.front());
    } else {
        std::cerr << "Failed to create enemy instance.\n";
    }

}

// Update game logic, player and enemy states
void game::Updater() {

    if (!playerInstance) return;

    playerInstance->Update(DeltaTime);

    // Aktualizuj wszystkich wrogów
    for (auto& enemy : basicEnemies) {
        if (enemy) {
            enemy->Update(DeltaTime);
            enemy->chasePlayer(getPlayerShape(), DeltaTime);
        }
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

