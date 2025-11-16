#include "inputManager.h"
#include "entities/player/player.h"
#include "entities/projectile/projectileEntity.h"
#include "SFML/Window/Keyboard.hpp"

// Function to get player movement direction based on keyboard input
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
    //std::cout << "Speed: " << speed << std::endl;

    return direction;
}

void inputManager::isMouseButtonPressed(bool &isLMBPressed, sf::Vector2f playerPosition, std::vector<std::unique_ptr<projectileEntity>>& projectiles) {
    if (isLMBPressed == true) {
        projectiles.push_back(std::make_unique<projectileEntity>(playerPosition, sf::Vector2f(0.f, -500.f), 2.0f));
        isLMBPressed = false;
    }
}
