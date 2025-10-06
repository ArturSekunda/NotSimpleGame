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
    int vitality = 0;

    int points = 0;

    void addPoints(int p) { points += p; }

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