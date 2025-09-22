#include "core/game.h"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "handlers/debugHandler.h"


int main() {

    sf::Clock DeltaTimeClock;

    bool DeveloperMode = true;

    game::getInstance().initializeEntities();

    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    // Create a Window and render it
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test", sf::Style::Default, settings);

    // Get player and enemy shapes
    sf::Shape &Player = game::getInstance().getPlayerShape();
    sf::Shape &Enemy = game::getInstance().getEnemyShape();


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

        game::getInstance().setDeltaTime(DeltaTimeClock.restart().asSeconds());
        // Update Game Logic

        game::getInstance().Updater();

        // Debug Info
        //std::cout << "Enemy position: " << enemyShape.getPosition().x << ", " << enemyShape.getPosition().y << std::endl;
        //std::cout << "Player position: " << playerShape.getPosition().x << ", " << playerShape.getPosition().y << std::endl;

        // Get Global Bounds
        sf::FloatRect playerBounds = Player.getGlobalBounds();
        sf::FloatRect enemyBounds = Enemy.getGlobalBounds();

        // Collision Detection
        if (debugHandler::getInstance().getWantToShowCollisionBoxes()) {

            game::getInstance().getPlayerCollisionBox().setPosition(Player.getPosition());
            game::getInstance().getEnemyCollisionBox().setPosition(Enemy.getPosition());
        }

        if (playerBounds.intersects(enemyBounds)) {
           // std::cout << "Collision Detected!" << std::endl;
            //TODO: Handle Collision
        }
        //std::cout << "isMoving: " << isMoving << std::endl;

        // Camera Follow Player
        if (game::getInstance().getPlayerPtr()->getIsMoving()) {
            CameraView.setCenter(Player.getPosition());
            window.setView(CameraView);
        }

        window.clear();

        // Draw everything here
        if (debugHandler::getInstance().getWantToShowCollisionBoxes()) {
            window.draw(game::getInstance().getPlayerCollisionBox());
            window.draw(game::getInstance().getEnemyCollisionBox());
        }
        window.draw(Player);
        window.draw(Enemy);

        window.display();
    }
    return 0;
}