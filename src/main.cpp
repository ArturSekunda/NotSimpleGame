#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

float calculateDistance(const sf::Vector2f& pointA, const sf::Vector2f& pointB) {
    float deltaX = pointB.x - pointA.x;
    float deltaY = pointB.y - pointA.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

int main() {

    bool DebugeMode = false;

    // Create a Window and render it
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");
    // Creating a circleShape (Player)
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(350, 250);
    shape.setOrigin(shape.getRadius(), shape.getRadius());

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


    window.setFramerateLimit(60);
    auto speed  =  200.f;
    auto enemySpeed = 100.f;

    while (window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
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

        //DeltaTime
        auto deltaTime = clock.restart().asSeconds();


        sf::Vector2f shapePos = shape.getPosition();
        sf::Vector2f enemyPos = enemy.getPosition();
        float distance = calculateDistance(shapePos, enemyPos);
        sf::Vector2f direction = shapePos - enemyPos;
        enemy.move(direction * (enemySpeed / distance) * deltaTime);
        std::cout << "Distance: " << distance << std::endl;
        std::cout << "Direction: " << direction.x << ", " << direction.y << std::endl;

        if (DebugeMode) {
            std::cout << "Player: " << shapePos.x << ", " << shapePos.y << std::endl;
            std::cout << "Enemy: " << enemyPos.x << ", " << enemyPos.y << std::endl;
        }


        // Check if key is pressed
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            speed = 400.f;
        }else {
            speed = 200.f;
        }

            window.clear();
            window.draw(shape);
            window.draw(enemy);
            window.display();
        }

        return 0;
    }