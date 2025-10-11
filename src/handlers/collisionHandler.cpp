

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

void collisionHandler::render(sf::RenderWindow &window, sf::RectangleShape& playerCollisionBox,
     const std::vector<std::unique_ptr<baseEntity>> &entitylist,const sf::Shape& playerShape) {


          // Collision box for player
          playerCollisionBox.setPosition(playerShape.getPosition());
          window.draw(playerCollisionBox);

          // Collision boxes for enemies
          for (const auto& enemy : entitylist) {
               if (enemy && enemy->getCollisionBox()) {
                    auto& enemyBox = *enemy->getCollisionBox();
                    enemyBox.setPosition(enemy->getEntityShape()->getPosition());
                    window.draw(enemyBox);
               }
          }

}
