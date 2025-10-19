#ifndef NOTSIMPLEGAME_ITEMSTRUCTS_H
#define NOTSIMPLEGAME_ITEMSTRUCTS_H
#include <iostream>
#include <ostream>
#include "items/helpers/enumConversion.h"
#include "itemEnums.h"
#include <string>

struct UUID {
    int id = 0;
    ItemType ItemType = ItemType::NONE;
    std::string ItemName = "None";
    int ItemLevel = 0;

    void DisplayUUID() const {
        auto& EC = enumConversion::getInstance();
        std::cout << "UUID: " +
            std::to_string(id) + "_" + EC.GetItemTypeNames().at(ItemType) + "_" + ItemName + "_" + std::to_string(ItemLevel) << std::endl;
    }
};

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