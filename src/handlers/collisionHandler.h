//
// Created by lukas on 22.09.2025.
//

#ifndef NOTSIMPLEGAME_COLLISIONHANDLER_H
#define NOTSIMPLEGAME_COLLISIONHANDLER_H
#include <memory>
#include <vector>


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

    std::vector<int> checkAllCollisions(const sf::Shape& player, const std::vector<std::shared_ptr<basicEnemy>>& enemies);


};


#endif //NOTSIMPLEGAME_COLLISIONHANDLER_H