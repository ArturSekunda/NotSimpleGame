//
// Created by lukas on 21.09.2025.
//

#include "baseEntity.h"


baseEntity::baseEntity(int localID):
health(100.0f),
maxHealth(100.0f),
mana(50.0f),
maxMana(50.0f),
defense(0.0f),
speed(100.0f),
isAlive(true),
strength(10),
dexterity(10),
intelligence(10),
endurance(10),
luck(10),
charisma(10),
entityShape(nullptr),
collisionBox(nullptr)

{
    entityID.localID = localID;



}

// Update method to update the entity's state
void baseEntity::Update(float deltaTime) {
    // Update entity logic here (e.g., regeneration, status effects)
    if (health <= 0) {
        isAlive = false;
    }
}

// Method to get the global bounds of the entity's shape for collision detection
sf::FloatRect baseEntity::getEntityBounds() const {
    if (entityShape == nullptr) {
        // Return bounds based on position with default size
        return sf::FloatRect(entityShape->getPosition().x, entityShape->getPosition().y, 32.0f, 32.0f);
    }
    return entityShape->getGlobalBounds();
}

// Method to create a collision box based on the entity's shape
sf::RectangleShape baseEntity::createCollisionBox() const {
    sf::RectangleShape Box;
    if (!entityShape) {
        return Box;
    }

    sf::FloatRect bounds = entityShape->getGlobalBounds();

    Box.setSize(sf::Vector2f(bounds.width, bounds.height));
    Box.setFillColor(sf::Color::Transparent);
    Box.setOutlineColor(sf::Color::White);
    Box.setOutlineThickness(2);

    Box.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    return Box;
}
