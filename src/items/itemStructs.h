#ifndef NOTSIMPLEGAME_ITEMSTRUCTS_H
#define NOTSIMPLEGAME_ITEMSTRUCTS_H
#include "itemEnums.h"
#include <string>
#include <vector>

struct ItemBonusStats {

    int strength = 0;
    int dexterity = 0;
    int intelligence = 0;
    int endurance = 0;
    int luck = 0;
    int charisma = 0;
    int vitality = 0;

};

struct Enchantment {
    std::string name = "None";
    std::string description = "No enchantment";
    EnchantType type = EnchantType::NONE;
    int power = 0;

};
#endif //NOTSIMPLEGAME_ITEMSTRUCTS_H