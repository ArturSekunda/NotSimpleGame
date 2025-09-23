#include "core/game.h"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "handlers/collisionHandler.h"
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
    sf::Shape& playerShape = game::getInstance().getPlayerShape();



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

        // Delta Time Calculation
        game::getInstance().setDeltaTime(DeltaTimeClock.restart().asSeconds());

        // Update Game Logic
        game::getInstance().Updater();

        auto enemies = game::getInstance().getEnemyPtrTable();

        // Collision Detection
        std::vector<int> collidingEnemies = collisionHandler::getInstance().checkAllCollisions(playerShape, enemies);

        // Handle Collisions
        for (auto& enemy : enemies) {
            if (enemy && enemy->getEntityShape()) {
                sf::FloatRect playerBounds = game::getInstance().getPlayerShape().getGlobalBounds();
                sf::FloatRect enemyBounds = enemy->getEntityShape()->getGlobalBounds();

                if (playerBounds.intersects(enemyBounds)) {
                    std::cout << "Collision with enemy!\n";
                    std::cout << "Enemies count: " << collidingEnemies.size() << "\n";
                }
            }
        }

        // Camera Follow Player
        if (game::getInstance().getPlayerPtr()->getIsMoving()) {
            CameraView.setCenter(Player.getPosition());
            window.setView(CameraView);
        }

        window.clear();


        // Draw debug info
        if (debugHandler::getInstance().getWantToShowCollisionBoxes()) {
            window.draw(game::getInstance().getPlayerCollisionBox());
            for (const auto& enemy : enemies) {
                if (enemy && enemy->getCollisionBox()) {
                    window.draw(*enemy->getCollisionBox());
                }
            }
        }

        window.draw(Player);
        for (const auto& enemy : enemies) {
            if (enemy && enemy->getEntityShape()) {
                window.draw(*enemy->getEntityShape());
            }
        }

        window.display();
    }
    return 0;
}