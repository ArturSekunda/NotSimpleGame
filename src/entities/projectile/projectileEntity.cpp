#include "projectileEntity.h"

projectileEntity::projectileEntity(sf::Vector2f position, sf::Vector2f velocity, float lifetimeSeconds) : velocity(velocity), maxLifetime(lifetimeSeconds) {
    auto circle = std::make_shared<sf::CircleShape>(5.0f);
    circle->setPosition(position);
    circle->setFillColor(sf::Color::Red);
    circle->setOrigin(5.0f, 5.0f);

    Shape = circle;

    this->collisionBox = std::make_shared<sf::RectangleShape>(createCollisionBox());

    lifetime.restart();
}

void projectileEntity::update(float deltaTime) {
    Shape->move(velocity*deltaTime);
}

void projectileEntity::draw(sf::RenderWindow &window) {
    window.draw(*Shape);
}

// Method to get the global bounds of the entity's shape for collision detection
sf::FloatRect projectileEntity::getEntityBounds() const {
    if (Shape == nullptr) {
        // Return bounds based on position with default size
        return {Shape->getPosition().x, Shape->getPosition().y, 32.0f, 32.0f};
    }
    return Shape->getGlobalBounds();
}

// Method to create a collision box based on the entity's shape
sf::RectangleShape projectileEntity::createCollisionBox() const {
    sf::RectangleShape Box;
    if (!Shape) {
        return Box;
    }

    sf::FloatRect bounds = Shape->getGlobalBounds();

    Box.setSize(sf::Vector2f(bounds.width, bounds.height));
    Box.setFillColor(sf::Color::Transparent);
    Box.setOutlineColor(sf::Color::White);
    Box.setOutlineThickness(2);

    Box.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    return Box;
}

void projectileEntity::updateProjectiles(float deltaTime, std::vector<std::unique_ptr<projectileEntity>>& projectiles) {
    for (auto& projectile : projectiles) {
        projectile->update(deltaTime);
    }
}

void projectileEntity::drawProjectiles(sf::RenderWindow& window, std::vector<std::unique_ptr<projectileEntity>>& projectiles) {
    for (auto& projectile : projectiles) {
        projectile->draw(window);
    }
}

void projectileEntity::cleanupProjectiles(std::vector<std::unique_ptr<projectileEntity>>& projectiles) {
    projectiles.erase(
        std::remove_if(projectiles.begin(), projectiles.end(),
            [](const auto& projectile) {
                return projectile->isExpired();
            }),
        projectiles.end()
    );
}
