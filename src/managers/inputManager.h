


#ifndef NOTSIMPLEGAME_INPUTMANAGER_H
#define NOTSIMPLEGAME_INPUTMANAGER_H
#include <memory>
#include <vector>

#include "SFML/System/Clock.hpp"
#include "SFML/System/Vector2.hpp"

class projectileEntity;

namespace sf {
    class View;
    class RenderWindow;
    class Event;
}

class debugHandler;

class inputManager {
public:
    static inputManager& getInstance() {
        static inputManager instance;
        return instance;
    }
    sf::Vector2f pMovementDirection(float deltaTime,float speed);

    sf::Clock clickClock;

    void isMouseButtonPressed(sf::Vector2f playerPosition, std::vector<std::unique_ptr<projectileEntity>>& projectiles, const sf::View& view);
};


#endif //NOTSIMPLEGAME_INPUTMANAGER_H