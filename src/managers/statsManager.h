//
// Created by Artur on 25.09.2025.
//

#ifndef NOTSIMPLEGAME_STATSMANAGER_H
#define NOTSIMPLEGAME_STATSMANAGER_H
#include <iostream>
#include <ostream>

class player;

struct baseStats {

    int strength = 0;
    int dexterity = 0;
    int intelligence = 0;
    int endurance = 0;
    int luck = 0;
    int charisma = 0;

    int points = 0;

    void addPoints(int p) { points += p; }

    void printStats() const {
        std::cout << "================================" << std::endl;
        std::cout << "1. Strength: " << strength << std::endl;
        std::cout << "2. Dexterity: " << dexterity << std::endl;
        std::cout << "3. Intelligence: " << intelligence << std::endl;
        std::cout << "4. Endurance: " << endurance << std::endl;
        std::cout << "5. Luck: " << luck << std::endl;
        std::cout << "6. Charisma: " << charisma << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << "Points: " << points << std::endl;
    }

    void addStats(const baseStats& stats) {
        if (stats.points == 0) {
            std::cout << "No points to add" << std::endl;
            return;
        }
    }



};

class statsManager {
public:
    statsManager() = default;
    ~statsManager() = default;
    static statsManager& getInstance() {
        static statsManager instance;
        return instance;
    }

    void levelUp(player& p);





};

#endif //NOTSIMPLEGAME_STATSMANAGER_H