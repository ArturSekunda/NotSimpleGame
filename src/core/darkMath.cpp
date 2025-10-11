

#include "darkMath.h"
#include <cmath>

// Function to calculate distance between two points
float darkMath::calculateDistance(const sf::Vector2f& pointA, const sf::Vector2f& pointB) {
    float deltaX = pointB.x - pointA.x;
    float deltaY = pointB.y - pointA.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

// Function to move towards a direction
sf::Vector2f darkMath::goTowards(float deltaTime, float speed, sf::Vector2f direction, float distance) {
    if (distance > 0.f) {
        sf::Vector2f normalizedDirection = direction / distance;
        return normalizedDirection * speed * deltaTime;
    }
    return sf::Vector2f(0.f, 0.f);
}

// Function to get direction vector from one point to another
sf::Vector2f darkMath::vectorDirection(const sf::Vector2f &from, const sf::Vector2f &to) {
    return to - from;
}

// Random int number generation
int darkMath::generateIntNumber(int min, int max) {
    std::uniform_int_distribution<int> distr(min, max);
    return distr(gen);
}

// Random float number generation
float darkMath::generateFloatNumber(float min, float max) {
    std::uniform_real_distribution<float> distr(min, max);
    return distr(gen);
}
