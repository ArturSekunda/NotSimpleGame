//
// Created by lukas on 22.09.2025.
//

#include "player.h"

#include <SFML/Graphics/CircleShape.hpp>


void player::createPlayerShape() {
    auto circle = std::make_shared<sf::CircleShape>(100.f);
    circle->setFillColor(sf::Color::Green);
    circle->setOrigin(circle->getRadius(), circle->getRadius());
    this->entityShape = circle;
}

sf::RectangleShape player::createCollisionBox() {
    sf::RectangleShape collisionBox;
    if (!entityShape) {
        return collisionBox;
    }


    sf::FloatRect bounds = entityShape->getGlobalBounds();


    collisionBox.setSize(sf::Vector2f(bounds.width, bounds.height));
    collisionBox.setFillColor(sf::Color::Transparent);
    collisionBox.setOutlineColor(sf::Color::Blue);
    collisionBox.setOutlineThickness(2);


    collisionBox.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    return collisionBox;
}

player::player() {
    createPlayerShape();
    this->collisionBox = std::make_shared<sf::RectangleShape>(createCollisionBox());
    if (!entityShape) {
        throw std::runtime_error("Failed to create player shape.");
    }
    // Set initial position
    position = sf::Vector2f(100.f, 100.f);
    if (entityShape) {
        entityShape->setPosition(position);
    } else {
        position = sf::Vector2f(0.f, 0.f);
        entityShape->setPosition(position);
    }
    this->speed = 200.f;
    this->health = 100.f;
    this->maxHealth = 100.f;
    this->mana = 50;
    this->maxMana = 50;
    this->isAlive = true;
}