
#ifndef NOTSIMPLEGAME_STATSMANAGER_H
#define NOTSIMPLEGAME_STATSMANAGER_H
#include <iostream>
#include <ostream>

struct ItemBonusStats;
class player;

struct baseStats{

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

    void addStrength(int s) {
        if (points <= 0) {
            return;
        }
        strength += s;
        points -= s;
    }
    void addDexterity(int d) {
        if (points <= 0) {
            return;
        }
        dexterity += d;
        points -= d;
    }
    void addIntelligence(int i) {
        if (points <= 0) {
            return;
        }
        intelligence += i;
        points -= i;
    }
    void addEndurance(int e) {
        if (points <= 0) {
            return;
        }
        endurance += e;
        points -= e;
    }
    void addLuck(int l) {
        if (points <= 0) {
            return;
        }
        luck += l;
        points -= l;
    }
    void addCharisma(int c) {
        if (points <= 0) {
            return;
        }
        charisma += c;
        points -= c;
    }
    void addVitality(int v) {
        if (points <= 0) {
            return;
        }
        vitality += v;
        points -= v;
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

    bool ApplyStatsPointsFromEquipment(baseStats& stats, const ItemBonusStats& bonusStats);





};

#endif //NOTSIMPLEGAME_STATSMANAGER_H