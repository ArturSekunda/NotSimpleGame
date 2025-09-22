

#ifndef NOTSIMPLEGAME_DARKMATH_H
#define NOTSIMPLEGAME_DARKMATH_H

#include "SFML/System/Vector2.hpp"

class SFML;
class darkMath {

public:
    static float calculateDistance(const sf::Vector2f& pointA, const sf::Vector2f& pointB);
    static sf::Vector2f goTowards(float deltaTime, float speed, sf::Vector2f direction, float distance);
    static sf::Vector2f vectorDirection(const sf::Vector2f& to, const sf::Vector2f& from);
};


#endif //NOTSIMPLEGAME_DARKMATH_H