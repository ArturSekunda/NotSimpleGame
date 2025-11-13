


#ifndef NOTSIMPLEGAME_INPUTMANAGER_H
#define NOTSIMPLEGAME_INPUTMANAGER_H
#include <memory>
#include <vector>
#include "entities/projectile/projectileEntity.h"
#include "SFML/System/Vector2.hpp"

namespace sf {
    class RenderWindow;
    class Event;
}

class debugHandler;

class inputManager {
    std::vector<std::unique_ptr<projectileEntity>> projectiles;
public:
    static inputManager& getInstance() {
        static inputManager instance;
        return instance;
    }
    sf::Vector2f pMovementDirection(float deltaTime,float speed);

    void isMouseButtonPressed(bool &isLMBPressed, sf::Vector2f playerPosition);

    void updateProjectiles(float deltaTime);
    void drawProjectiles(sf::RenderWindow& window);
    void cleanupProjectiles();
};


#endif //NOTSIMPLEGAME_INPUTMANAGER_H