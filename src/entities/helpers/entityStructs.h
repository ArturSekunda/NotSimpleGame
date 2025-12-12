#ifndef NOTSIMPLEGAME_ENTITYSTRUCTS_H
#define NOTSIMPLEGAME_ENTITYSTRUCTS_H

#include "entityEnums.h"
#include <string>
#include <vector>
struct baseStats{

    int strength = 0;
    int dexterity = 0;
    int intelligence = 0;
    int endurance = 0;
    int luck = 0;
    int charisma = 0;
    int vitality = 0;

    // Cache
    int CachedStrength = 0;
    int CachedDexterity = 0;
    int CachedIntelligence = 0;
    int CachedEndurance = 0;
    int CachedLuck = 0;
    int CachedCharisma = 0;
    int CachedVitality = 0;

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

    void subtractStats(const std::vector<int> &stats) {
        strength -= stats[0];
        dexterity -= stats[1];
        intelligence -= stats[2];
        endurance -= stats[3];
        luck -= stats[4];
        charisma -= stats[5];
        vitality -= stats[6];
    }

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

struct EntityID {
    EntityType type;  // PLAYER, BASIC_ENEMY, GOBLIN, ETC...
    int localID;

    std::string toString() const {
        return typeToString(type) + "_" + std::to_string(localID);
    }

    static std::string typeToString(EntityType type) {
        switch (type) {
            case EntityType::PLAYER: return "player";
            case EntityType::BASIC_ENEMY: return "basic_enemy";
            default:
                return "unknown";

        }
    }
};


#endif //NOTSIMPLEGAME_ENTITYSTRUCTS_H