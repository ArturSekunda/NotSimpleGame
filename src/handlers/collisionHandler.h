//
// Created by lukas on 22.09.2025.
//

#ifndef NOTSIMPLEGAME_COLLISIONHANDLER_H
#define NOTSIMPLEGAME_COLLISIONHANDLER_H
#include "SFML/Graphics/Rect.hpp"


class collisionHandler {
public:
    collisionHandler();
    static collisionHandler& getInstance() {
        static collisionHandler instance;
        return instance;
    }

    bool isColliding(sf::FloatRect& player, sf::FloatRect& enemy);
};


#endif //NOTSIMPLEGAME_COLLISIONHANDLER_H