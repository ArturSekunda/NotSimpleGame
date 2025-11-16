#ifndef NOTSIMPLEGAME_PROJECTILEENTITY_H
#define NOTSIMPLEGAME_PROJECTILEENTITY_H
#include "entities/baseEntity.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"


class projectileEntity : public sf::Clock, public sf::Vector2f{
    sf::Vector2f velocity;
    Clock lifetime;
    float maxLifetime;
    std::shared_ptr<sf::Shape> Shape;
    std::shared_ptr<sf::RectangleShape> collisionBox;
public:

    projectileEntity(sf::Vector2f position, sf::Vector2f velocity, float lifetimeSeconds = 2.0f);
    ~projectileEntity() = default;

    void update(float deltaTime);

    bool isExpired() const {
        return lifetime.getElapsedTime().asSeconds() >= maxLifetime;
    }

    void draw(sf::RenderWindow& window);

    sf::FloatRect getEntityBounds() const;

    sf::RectangleShape createCollisionBox() const;

    static void updateProjectiles(float deltaTime, std::vector<std::unique_ptr<projectileEntity>> &projectiles);

    static void drawProjectiles(sf::RenderWindow &window, std::vector<std::unique_ptr<projectileEntity>> &projectiles);

    static void cleanupProjectiles(std::vector<std::unique_ptr<projectileEntity>> &projectiles);

    sf::Vector2f getPosition() const {
        return Shape->getPosition();
    }

    std::shared_ptr<sf::Shape> getEntityShape() const { return Shape; }
    std::shared_ptr<sf::RectangleShape> getCollisionBox() const { return collisionBox; }

    void setEntityShape(std::shared_ptr<sf::Shape> shape) { Shape = shape; }
    void setCollisionBox(std::shared_ptr<sf::RectangleShape> box) { collisionBox = box; }



};


#endif //NOTSIMPLEGAME_PROJECTILEENTITY_H