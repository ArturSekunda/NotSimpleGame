//
// Created by lukas on 20.09.2025.
//


#ifndef NOTSIMPLEGAME_INPUTMANAGER_H
#define NOTSIMPLEGAME_INPUTMANAGER_H
#include "SFML/Window/Keyboard.hpp"

class SFML;

class inputManager {
    void processInput(sf::Keyboard *keyboard);
};


#endif //NOTSIMPLEGAME_INPUTMANAGER_H