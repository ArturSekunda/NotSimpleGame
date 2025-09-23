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
std::vector<int> collisionHandler::checkAllCollisions(const sf::Shape& player, const std::vector<std::shared_ptr<basicEnemy>>& enemies) {
     std::vector<int> collidingEnemies;

     for (int i = 0; i < enemies.size(); i++) {
          if (enemies[i] && enemies[i]->getEntityShape()) {
               if (isColliding(player, *enemies[i]->getEntityShape())) {
                    collidingEnemies.push_back(i);
               }
          }
     }

     return collidingEnemies;
}