

#include "core/darkMath.h"
#include "basicEnemy.h"

#include <iostream>

#include "entities/player/player.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/ConvexShape.hpp"



basicEnemy::basicEnemy(int localID, int playerLevel) : baseEntity(localID) {

    entityID.type = EntityType::BASIC_ENEMY;
    entityID.localID = localID;

    createRandomEnemyShape();
    this->collisionBox = std::make_shared<sf::RectangleShape>(createCollisionBox());
    if (!entityShape) {
        throw std::runtime_error("Failed to create enemy shape.");
    }
    // Set initial position
    auto position = sf::Vector2f(
        darkMath::getInstance().generateFloatNumber(0.f, 800.f),
        darkMath::getInstance().generateFloatNumber(0.f, 600.f)
    );
    entityShape->setPosition(position);
    if (entityShape) {
        entityShape->setPosition(position);
    } else {
        position = sf::Vector2f(0.f, 0.f);
        entityShape->setPosition(position);
    }
    this->level = darkMath::getInstance().generateIntNumber(playerLevel, playerLevel + 5);
    this->speed = darkMath::getInstance().generateFloatNumber(50.f, 150.f);
    this->health = darkMath::getInstance().generateFloatNumber(50.f*level, 50.f+50.f*level);
    this->maxHealth = this->health;
    this->isAlive = true;


}

void basicEnemy::createRandomEnemyShape() {
    int shapeType = darkMath::getInstance().generateIntNumber(0, 2);
    switch (shapeType) {
        case 0: {
            auto circle = std::make_shared<sf::CircleShape>(100.f);
            circle->setFillColor(sf::Color::Red);
            circle->setOrigin(circle->getRadius(), circle->getRadius());
            this->entityShape = circle;
            break;
        }
        case 1:  {
            auto rectangle = std::make_shared<sf::RectangleShape>(sf::Vector2f(200.f, 100.f));
            rectangle->setFillColor(sf::Color::Blue);
            rectangle->setOrigin(rectangle->getSize().x / 2, rectangle->getSize().y / 2);
            this->entityShape = rectangle;
            break;
        }
        case 2: {
            auto triangle = std::make_shared<sf::ConvexShape>(3);
            triangle->setPoint(0, sf::Vector2f(0.f, -100.f));
            triangle->setPoint(1, sf::Vector2f(100.f, 100.f));
            triangle->setPoint(2, sf::Vector2f(-100.f, 100.f));
            triangle->setFillColor(sf::Color::Yellow);
            triangle->setOrigin(0.f, 0.f); // Approximate center
            this->entityShape = triangle;
            break;
        }
        default:
            std::cerr << "Invalid shape type!" << std::endl;
            break;
    }


}

void basicEnemy::chasePlayer(sf::Shape &player, const float &deltaTime) {
    sf::Vector2f ToThePlayer = darkMath::getInstance().goTowards(
        deltaTime,
        getSpeed(),
        darkMath::getInstance().vectorDirection(getPosition(), player.getPosition()),
        darkMath::getInstance().calculateDistance(getPosition(), player.getPosition())
    );
    entityShape->move(sf::Vector2f(ToThePlayer.x, ToThePlayer.y));
}

bool basicEnemy::isDead(Inventory& playerInventory) {
    if (this->health > 0.f) {
        return false;
    }

    equipment.DropEquipmentOnDeath(playerInventory);

    return true;
}

void basicEnemy::Update(float deltaTime) {
    baseEntity::Update(deltaTime);

}
