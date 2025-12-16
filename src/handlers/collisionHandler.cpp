

#include "collisionHandler.h"

#include <iostream>
#include <SFML/Graphics/Shape.hpp>

#include "entities/enemies/basicEnemy.h"
#include "entities/projectile/projectileEntity.h"

// Check if two shapes are colliding using their global bounds
bool collisionHandler::isColliding(const sf::Shape &player, const sf::Shape &enemy) {

     return player.getGlobalBounds().intersects(enemy.getGlobalBounds());
}

// Check collisions with all enemies and return indices of colliding ones
std::vector<basicEnemy*> collisionHandler::checkAllCollisions(const sf::Shape &player, const std::vector<std::unique_ptr<basicEnemy>>& entitylist) {

     std::vector<basicEnemy*> collisions;

     for (const auto& entity : entitylist) {
          if (entity && isColliding(player, *entity->getEntityShape())) {
               collisions.push_back(entity.get());
          }
     }

     return collisions;
}

void collisionHandler::render(sf::RenderWindow &window, sf::RectangleShape& playerCollisionBox,
     const std::vector<std::unique_ptr<basicEnemy>> &entitylist,const sf::Shape& playerShape) {


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

auto collisionHandler::renderProjectileCollisionBox(sf::RenderWindow &window, std::vector<std::unique_ptr<projectileEntity>>& projectiles) -> void {
     for (const auto& projectile : projectiles) {
          if (projectile && projectile->getCollisionBox()) {
               auto& projectileBox = *projectile->getCollisionBox();
               projectileBox.setPosition(projectile->getPosition());
               window.draw(projectileBox);
          }
     }
}
