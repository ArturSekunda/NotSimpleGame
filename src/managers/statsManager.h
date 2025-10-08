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
    void subtractPoints(int p) { points -= p; }

    void setStrength(int s) { strength = s;}
    void setDexterity(int d) { dexterity = d; }
    void setIntelligence(int i) { intelligence = i; }
    void setEndurance(int e) { endurance = e; }
    void setLuck(int l) { luck = l; }
    void setCharisma(int c) { charisma = c; }
    void setVitality(int v) { vitality = v; }


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