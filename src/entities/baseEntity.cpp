//
// Created by lukas on 21.09.2025.
//

#include "baseEntity.h"

void baseEntity::Update(float deltaTime) {
    // Update entity logic here (e.g., regeneration, status effects)
    if (health <= 0) {
        isAlive = false;
    }
}

sf::FloatRect baseEntity::getEntityBounds() const {
    if (entityShape == nullptr) {
        // Return bounds based on position with default size
        return sf::FloatRect(position.x, position.y, 32.0f, 32.0f);
    }
    return entityShape->getGlobalBounds();
}
