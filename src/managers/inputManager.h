


#ifndef NOTSIMPLEGAME_INPUTMANAGER_H
#define NOTSIMPLEGAME_INPUTMANAGER_H
#include "SFML/System/Vector2.hpp"

namespace sf {
    class Event;
}

class debugHandler;

class inputManager {
    inputManager() = default;
public:
    static inputManager& getInstance() {
        static inputManager instance;
        return instance;
    }
    sf::Vector2f pMovementDirection(float deltaTime,float speed);
};


#endif //NOTSIMPLEGAME_INPUTMANAGER_H