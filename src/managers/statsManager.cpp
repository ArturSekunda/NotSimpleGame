
#include "statsManager.h"
#include <cmath>
#include <iostream>

#include "entities/player/player.h"

void statsManager::levelUp(player& p) {
    while (p.getEXP() >= p.getEXP_MAX()) {

        p.setEXP(p.getEXP() - p.getEXP_MAX());

        p.setLevel(p.getLevel() + 1);

        p.getStats().addPoints(1);

        auto baseEXP = 500.0f;
        auto growthRate = 1.25f;
        auto newEXP_MAX = baseEXP * std::pow(growthRate, p.getLevel() - 1);

        p.setEXP_MAX(static_cast<float>(newEXP_MAX));
        std::cout << "Level up!" << " New level: " << p.getLevel() << "\n";
        std::cout << "Points: " << p.getStats().points << "\n";
    }
}

