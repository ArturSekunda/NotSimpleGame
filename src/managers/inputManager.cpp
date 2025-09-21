
#include "inputManager.h"

#include <iostream>

#include "SFML/Window/Keyboard.hpp"


sf::Vector2f inputManager::pMovementDirection(float deltaTime, float speed) {
    sf::Vector2f direction(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        speed *= 2.f;
    }else {
        speed = (speed / 2.f) * 2.f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        direction.x -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        direction.x += speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        direction.y -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        direction.y += speed * deltaTime;
    }
    std::cout << "Speed: " << speed << std::endl;
    return direction;
}
