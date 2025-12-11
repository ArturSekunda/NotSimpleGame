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

    std::vector<int> toVector() const {
        return {strength, dexterity, intelligence, endurance, luck, charisma, vitality};
    }

};

struct EnchantmentWeapon {
    std::string name = "None";
    std::string description = "No enchantment";
    EnchantWeaponType type = EnchantWeaponType::NONE;
    int power = 0;

};

struct EnchantmentArmor {
    std::string name = "None";
    std::string description = "No enchantment";
    EnchantArmorType type = EnchantArmorType::NONE;
    float HealthToAdd = 0.f;
    float ManaToAdd = 0.f;
    float ArmorToAdd = 0.f;
};
#endif //NOTSIMPLEGAME_ITEMSTRUCTS_H