#include "entities/player/player.h"
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
        std::cerr << "Failed to create player instance." << std::endl;
        return -1;
    }
    // Get the player's shape
    sf::Shape& shape = *playerPtr->getEntityShape();
    if (&shape == nullptr) {
        std::cerr << "Player shape is null." << std::endl;
        return -1;
    }


    // Get the player's collision box
    sf::RectangleShape& playerCollisionBox = *playerPtr->getCollisionBox();

    // Enemy Collision Box for Debugging
    sf::RectangleShape enemyBoundsRect;
    enemyBoundsRect.setSize(sf::Vector2f(200.f, 200.f));
    enemyBoundsRect.setFillColor(sf::Color::Transparent);
    enemyBoundsRect.setOutlineColor(sf::Color::Red);
    enemyBoundsRect.setOutlineThickness(2);
    enemyBoundsRect.setOrigin(enemyBoundsRect.getSize().x / 2, enemyBoundsRect.getSize().y / 2);


    // Enemy
    sf::CircleShape enemy(100.f);
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(50, 50);
    enemy.setOrigin(enemy.getRadius(), enemy.getRadius());

    // Clock for delta time
    sf::Clock clock;

    //Stats
    bool isMoving = false;


    window.setFramerateLimit(60);
    auto enemySpeed = 100.f;

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

        // Enemy Movement towards player
        enemy.move(darkMath::goTowards(deltaTime, enemySpeed, darkMath::vectorDirection(shape.getPosition(), enemy.getPosition()), darkMath::calculateDistance(shape.getPosition(), enemy.getPosition())));

        // Get Global Bounds
        sf::FloatRect playerBounds = shape.getGlobalBounds();
        sf::FloatRect enemyBounds = enemy.getGlobalBounds();

        // Collision Detection
        if (debugHandler::getInstance().getWantToShowCollisionBoxes()) {


            playerCollisionBox.setPosition(shape.getPosition());
            enemyBoundsRect.setPosition(enemy.getPosition());
        }

        if (playerBounds.intersects(enemyBounds)) {
            std::cout << "Collision Detected!" << std::endl;
            //TODO: Handle Collision
        }

        // Movement
        sf::Vector2f movement = inputManager::getInstance().pMovementDirection(deltaTime, playerPtr->getSpeed());
        if (movement.x != 0.f || movement.y != 0.f) {
            isMoving = true;
            shape.move(movement);
        }else {
            isMoving = false;
        }
        //std::cout << "isMoving: " << isMoving << std::endl;

        // Camera Follow Player
        if (isMoving) {
            CameraView.setCenter(shape.getPosition());
            window.setView(CameraView);
        }


        window.clear();

        // Draw everything here
        if (debugHandler::getInstance().getWantToShowCollisionBoxes()) {
            window.draw(playerCollisionBox);
            window.draw(enemyBoundsRect);
        }
        window.draw(shape);
        window.draw(enemy);

        window.display();
    }
    return 0;
}
