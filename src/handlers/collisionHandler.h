

#ifndef NOTSIMPLEGAME_COLLISIONHANDLER_H
#define NOTSIMPLEGAME_COLLISIONHANDLER_H
#include "entities/baseEntity.h"
#include <memory>
#include <vector>

#include "SFML/Graphics/RenderWindow.hpp"


class baseEntity;

namespace sf {
    class Shape;
}

class basicEnemy;

class collisionHandler {
public:

    collisionHandler() = default;

    ~collisionHandler() = default;

    static collisionHandler& getInstance() {
        static collisionHandler instance;
        return instance;
    }

    bool isColliding(const sf::Shape& player, const sf::Shape& enemy);

    std::vector<std::string> checkAllCollisions(const sf::Shape &player, const std::vector<std::unique_ptr<baseEntity>>& entitylist);
    auto render(sf::RenderWindow &window, sf::RectangleShape &playerCollisionBox,
                const std::vector<std::unique_ptr<baseEntity> > &entitylist, const sf::Shape &playerShape) -> void;


};


#endif //NOTSIMPLEGAME_COLLISIONHANDLER_H