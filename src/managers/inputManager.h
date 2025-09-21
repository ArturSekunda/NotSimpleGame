//
// Created by lukas on 20.09.2025.
//


#ifndef NOTSIMPLEGAME_INPUTMANAGER_H
#define NOTSIMPLEGAME_INPUTMANAGER_H
#include "SFML/System/Vector2.hpp"

class SFML;

class inputManager {
public:
    static sf::Vector2f pMovementDirection(float deltaTime,float speed);
};


#endif //NOTSIMPLEGAME_INPUTMANAGER_H