#include "entities/player/player.h"
#include "entities/enemies/basicEnemy.h"
#include "core/darkMath.h"
#include "managers/inputManager.h"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "handlers/debugHandler.h"


int main() {

    bool DeveloperMode = true;

    // Create a Window and render it
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");

    // Player
    auto playerPtr = std::make_unique<player>();
    if (!playerPtr) {
        std::cerr << "Failed to create player instance.\n";
        return -1;
    }
    // Get the player's shape
    sf::Shape& playerShape = *playerPtr->getEntityShape();
    if (&playerShape == nullptr) {
        std::cerr << "Player shape is null.\n";
        return -1;
    }

    // Movement flag
    bool isMoving = playerPtr->getIsMoving();

    // Enemy
    auto enemyPtr = std::make_unique<basicEnemy>();
    if (!enemyPtr) {
        std::cerr << "Failed to create enemy instance.\n";
        return -1;
    }
    sf::Shape& enemyShape = *enemyPtr->getEntityShape();
    if (&enemyShape == nullptr) {
        std::cerr << "Enemy shape is null.\n";
        return -1;
    }

    // Get the player's collision box
    sf::RectangleShape& playerCollisionBox = *playerPtr->getCollisionBox();

    // Enemy Collision Box for Debugging
    sf::RectangleShape& enemyCollisionBox = *enemyPtr->getCollisionBox();

    // Clock for delta time
    sf::Clock clock;

    window.setFramerateLimit(60);

    // Camera
    sf::View CameraView = window.getDefaultView();

    // Game Loop
    while (window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        // Create an event
        sf::Event event;
        // Event Handler
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::Resized){
                CameraView.setSize(event.size.width, event.size.height);
                window.setView(CameraView);
            }

            if (event.type == sf::Event::KeyPressed && DeveloperMode) {
                inputManager::getInstance().debugInput(event);
            }
        }

        //DeltaTime
        auto deltaTime = clock.restart().asSeconds();

        // Update Entities
        playerPtr->Update(deltaTime);
        enemyPtr->Update(deltaTime);

        // Enemy AI - Chase Player
        enemyPtr->chasePlayer(playerShape,deltaTime);

        // Debug Info
        //std::cout << "Enemy position: " << enemyShape.getPosition().x << ", " << enemyShape.getPosition().y << std::endl;
        //std::cout << "Player position: " << playerShape.getPosition().x << ", " << playerShape.getPosition().y << std::endl;

        // Get Global Bounds
        sf::FloatRect playerBounds = playerShape.getGlobalBounds();
        sf::FloatRect enemyBounds = enemyShape.getGlobalBounds();

        // Collision Detection
        if (debugHandler::getInstance().getWantToShowCollisionBoxes()) {

            playerCollisionBox.setPosition(playerShape.getPosition());
            enemyCollisionBox.setPosition(enemyShape.getPosition());
        }

        if (playerBounds.intersects(enemyBounds)) {
           // std::cout << "Collision Detected!" << std::endl;
            //TODO: Handle Collision
        }
        //std::cout << "isMoving: " << isMoving << std::endl;

        // Camera Follow Player
        if (isMoving) {
            CameraView.setCenter(playerShape.getPosition());
            window.setView(CameraView);
        }

        window.clear();

        // Draw everything here
        if (debugHandler::getInstance().getWantToShowCollisionBoxes()) {
            window.draw(playerCollisionBox);
            window.draw(enemyCollisionBox);
        }
        window.draw(playerShape);
        window.draw(enemyShape);

        window.display();
    }
    return 0;
}