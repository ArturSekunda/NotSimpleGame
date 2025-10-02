//
// Created by lukas on 22.09.2025.
//

#include "collisionHandler.h"

#include <iostream>
#include <SFML/Graphics/Shape.hpp>

#include "entities/enemies/basicEnemy.h"

// Check if two shapes are colliding using their global bounds
bool collisionHandler::isColliding(const sf::Shape &player, const sf::Shape &enemy) {

     return player.getGlobalBounds().intersects(enemy.getGlobalBounds());
}

// Check collisions with all enemies and return indices of colliding ones
std::vector<std::string> collisionHandler::checkAllCollisions(
    const sf::Shape &player,
    const std::vector<std::unique_ptr<baseEntity>>& entitylist
) {
     std::vector<std::string> collisions;

     for (const auto& entity : entitylist) {
          if (entity && isColliding(player, *entity->getEntityShape())) {
               collisions.push_back(entity->getEntityID().toString());
          }
     }

     return collisions;
}