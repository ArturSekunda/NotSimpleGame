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

    while (window.isOpen()) {
        sf::Event event;
        // Event Handler
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
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
