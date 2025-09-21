#include "math/darkMath.h"
#include "managers/inputManager.h"
#include <iostream>
#include <SFML/Graphics.hpp>


int main() {
    //For Debugging
    bool DebugeMode = true;

    // Create a Window and render it
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");

    // Creating a circleShape (Player)
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(350, 250);
    shape.setOrigin(shape.getRadius(), shape.getRadius());

    // For Debugging collision

    sf::RectangleShape playerBoundsRect;
    playerBoundsRect.setSize(sf::Vector2f(shape.getRadius() * 2, shape.getRadius() * 2));
    playerBoundsRect.setFillColor(sf::Color::Transparent);
    playerBoundsRect.setOutlineColor(sf::Color::Blue);
    playerBoundsRect.setOutlineThickness(2);
    playerBoundsRect.setOrigin(shape.getRadius(), shape.getRadius());

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
    auto playerHP = 100.f;
    auto enemyHP = 100.f;
    bool isMoving = false;


    window.setFramerateLimit(60);
    auto speed  =  200.f;
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
        }

        //DeltaTime
        auto deltaTime = clock.restart().asSeconds();

        // Enemy Movement towards player
        enemy.move(darkMath::goTowards(deltaTime, enemySpeed, darkMath::vectorDirection(shape.getPosition(), enemy.getPosition()), darkMath::calculateDistance(shape.getPosition(), enemy.getPosition())));

        // Get Global Bounds
        sf::FloatRect playerBounds = shape.getGlobalBounds();
        sf::FloatRect enemyBounds = enemy.getGlobalBounds();

        // Collision Detection
        if (DebugeMode) {
            playerBoundsRect.setPosition(shape.getPosition());
            enemyBoundsRect.setPosition(enemy.getPosition());
        }
        if (playerBounds.intersects(enemyBounds)) {
            std::cout << "Collision Detected!" << std::endl;
            //TODO: Handle Collision
        }

        // Movement
        sf::Vector2f movement = inputManager::pMovementDirection(deltaTime, speed);
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
        if (DebugeMode) {
            window.draw(playerBoundsRect);
            window.draw(enemyBoundsRect);
        }
        window.draw(shape);
        window.draw(enemy);

        window.display();
    }
    return 0;
}