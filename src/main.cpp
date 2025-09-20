#include <any>
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    // Create a Window and render it
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
    // Creating a circleShape
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(350, 250);
    sf::Clock clock;

    window.setFramerateLimit(60);
    auto speed  =  200.f;

    while (window.isOpen()) {
        // Create an event
        sf::Event event;
        // Event Handler
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            }
        }

        //Getting time

        auto deltaTime = clock.restart().asSeconds();
        if (deltaTime > 0.033f) {
            deltaTime = 0.033f;
        }


        // Check if key is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            shape.move(-speed * deltaTime, 0.f);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            shape.move(speed * deltaTime, 0.f);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            shape.move(0.f, -speed * deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            shape.move(0.f, speed * deltaTime);
        }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {

                std::cout << "Clocking clock: " << clock.getElapsedTime().asSeconds() << "."  << clock.getElapsedTime().asMicroseconds() << "\n";


            }else {
                clock.restart();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }

        return 0;
    }