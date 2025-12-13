#include "inputManager.h"

#include "core/darkMath.h"
#include "entities/player/player.h"
#include "entities/projectile/projectileEntity.h"
#include "handlers/eventHandler.h"
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

void inputManager::isMouseButtonPressed(sf::Vector2f playerPosition, std::vector<std:: unique_ptr<projectileEntity>>& projectiles,const sf::View& view) {

    bool IsHoldingMouse = eventHandler::getInstance().getWhenMouseClicked();

    if (IsHoldingMouse && clickClock.getElapsedTime().asSeconds() >= 0.3f) {

        sf::Vector2f mouseWorldPos = eventHandler::getInstance().getMouseWorldPosition(view);

        sf::Vector2f direction = darkMath::getInstance().vectorDirection(playerPosition, mouseWorldPos);

        projectiles.push_back(std:: make_unique<projectileEntity>(
            playerPosition,
            500.f,
            direction,
            2.0f
        ));

        clickClock.restart();
    }
}
