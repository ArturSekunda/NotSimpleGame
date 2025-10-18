#include "items/helpers/enumConversion.h"

void enumConversion::EnumsToVectorList() {
    rarity = {
        Rarity::COMMON,
        Rarity::UNCOMMON,
        Rarity::RARE,
        Rarity::EPIC,
        Rarity::LEGENDARY
    };

    prefix = {
        WeaponPrefix::Ancient,
        WeaponPrefix::Dark,
        WeaponPrefix::Blazing,
        WeaponPrefix::Frozen,
        WeaponPrefix::Cursed,
        WeaponPrefix::Divine,
        WeaponPrefix::Shadow,
        WeaponPrefix::Crimson,
        WeaponPrefix::Golden,
        WeaponPrefix::Silver,
        WeaponPrefix::Rusted,
        WeaponPrefix::Ethereal,
        WeaponPrefix::Vengeful,
        WeaponPrefix::Storm,
        WeaponPrefix::Blood,
        WeaponPrefix::Dragon,
        WeaponPrefix::Phantom,
        WeaponPrefix::Royal,
        WeaponPrefix::Mystic,
        WeaponPrefix::Demon
    };

    type = {
        WeaponType::SWORD,
        WeaponType::AXE,
        WeaponType::BOW,
        WeaponType::STAFF,
        WeaponType::SPEAR
    };

    modifier = {
        DamageType::Physical,
        DamageType::Fire,
        DamageType::Ice,
        DamageType::Electrical,
        DamageType::Poison,
        DamageType::Holy,
        DamageType::Bloody
    };
}

void enumConversion::EnumsToValues() {
    ModifierValues = {
        {DamageType::Physical, 0},
        {DamageType::Fire, 2},
        {DamageType::Ice, 3},
        {DamageType::Electrical, 4},
        {DamageType::Poison, 5},
        {DamageType::Holy, 6},
        {DamageType::Bloody, 7}
    };
}

std::vector<Rarity> enumConversion::GetRarity() {
    return rarity;
}

std::vector<WeaponPrefix> enumConversion::GetPrefix() {
    return prefix;
}

std::vector<WeaponType> enumConversion::GetType() {
    return type;
}

std::vector<DamageType> enumConversion::GetModifier() {
    return modifier;
}
