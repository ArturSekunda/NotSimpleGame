

#ifndef NOTSIMPLEGAME_DARKMATH_H
#define NOTSIMPLEGAME_DARKMATH_H

#include <chrono>
#include <random>

#include "SFML/System/Vector2.hpp"

class SFML;
class darkMath {
    std::random_device rd;
    std::mt19937 gen;

public:
    darkMath() {
        auto seed = rd() ^ std::chrono::high_resolution_clock::now().time_since_epoch().count();
        gen.seed(static_cast<std::mt19937::result_type>(seed));
    }

    static darkMath& getInstance() {
        static darkMath instance;
        return instance;
    }

    float calculateDistance(const sf::Vector2f& pointA, const sf::Vector2f& pointB);
    sf::Vector2f goTowards(float deltaTime, float speed, sf::Vector2f direction, float distance);
    sf::Vector2f vectorDirection(const sf::Vector2f& to, const sf::Vector2f& from);

    auto generateIntNumber(int min, int max) -> int;

    auto generateFloatNumber(float min, float max) -> float;

    auto generateDistanceDistribution(const std::vector<int>& weights) -> int;

    auto UniformIntDistribution(int min, int max) -> int;

};


#endif //NOTSIMPLEGAME_DARKMATH_H