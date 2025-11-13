#ifndef NOTSIMPLEGAME_PROJECTILEENTITY_H
#define NOTSIMPLEGAME_PROJECTILEENTITY_H
#include "entities/baseEntity.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"


class projectileEntity : public sf::Clock, public sf::Vector2f{
    sf::CircleShape shape;
    sf::Vector2f velocity;
    Clock lifetime;
    float maxLifetime;
public:

    projectileEntity(sf::Vector2f position, sf::Vector2f velocity, float lifetimeSeconds = 2.0f);
    ~projectileEntity() = default;

    void update(float deltaTime);

    bool isExpired() const {
        return lifetime.getElapsedTime().asSeconds() >= maxLifetime;
    }

    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const {
        return shape.getPosition();
    }



};


#endif //NOTSIMPLEGAME_PROJECTILEENTITY_H