//
// Created by lukas on 22.09.2025.
//

#include "player.h"

#include <SFML/Graphics/CircleShape.hpp>


// Create a simple circular shape for the player
void player::createPlayerShape() {
    auto circle = std::make_shared<sf::CircleShape>(100.f);
    circle->setFillColor(sf::Color::Green);
    circle->setOrigin(circle->getRadius(), circle->getRadius());
    this->entityShape = circle;
}

void player::handleMovement(float deltaTime) {
    sf::Vector2f movement = inputManager::getInstance().pMovementDirection(deltaTime, getSpeed());
    if (movement.x != 0.f || movement.y != 0.f) {
        isMoving = true;
        entityShape->move(movement);
    }else {
        isMoving = false;
    }
}

void player::setPlayerStats() {

    // Core Stats
    this->speed = 200.f;
    this->health = 100.f;
    this->maxHealth = 100.f;
    this->mana = 50;
    this->maxMana = 50;
    this->isAlive = true;

    this->defense = 0.f;
}

player::player(int localID) : baseEntity(localID) {

    entityID.type = EntityType::PLAYER;
    entityID.localID = localID;

    createPlayerShape();
    setPlayerStats();
    this->collisionBox = std::make_shared<sf::RectangleShape>(createCollisionBox());
    if (!entityShape) {
        throw std::runtime_error("Failed to create player shape.");
    }
    // Set initial position
    entityShape->setPosition(sf::Vector2f(100.f, 100.f));
    if (entityShape) {
        entityShape->setPosition(sf::Vector2f(100.f, 100.f));
    } else {
        entityShape->setPosition(sf::Vector2f(0.f, 0.f));
    }
}

void player::Update(float deltaTime) {
    baseEntity::Update(deltaTime);
    handleMovement(deltaTime);
}
