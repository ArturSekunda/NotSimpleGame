//
// Created by lukas on 20.09.2025.
//

#include "darkMath.h"
#include <cmath>

// Function to calculate distance between two points
float darkMath::calculateDistance(const sf::Vector2f& pointA, const sf::Vector2f& pointB) {
    float deltaX = pointB.x - pointA.x;
    float deltaY = pointB.y - pointA.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

sf::Vector2f darkMath::goTowards(float deltaTime, float speed, sf::Vector2f direction, float distance) {
    return direction * (speed / distance) * deltaTime;
}

sf::Vector2f darkMath::vectorDirection(const sf::Vector2f &to, const sf::Vector2f &from) {
    return to - from;
}
