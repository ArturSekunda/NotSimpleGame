#include "projectileEntity.h"

projectileEntity::projectileEntity(sf::Vector2f position, sf::Vector2f velocity, float lifetimeSeconds) : velocity(velocity), maxLifetime(lifetimeSeconds) {
    shape.setPosition(position);
    shape.setRadius(5.0f);
    shape.setFillColor(sf::Color::Red);
    lifetime.restart();
}

void projectileEntity::update(float deltaTime) {
    shape.move(velocity*deltaTime);
}

void projectileEntity::draw(sf::RenderWindow &window) {
    window.draw(shape);
}
