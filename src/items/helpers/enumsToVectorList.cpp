#include "items/helpers/enumsToVectorList.h"

void enumsToVectorList::EnumsToVectorList() {
    rarityValues = {
        Rarity::COMMON,
        Rarity::UNCOMMON,
        Rarity::RARE,
        Rarity::EPIC,
        Rarity::LEGENDARY
    };

    prefixValues = {
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

    typeValues = {
        WeaponType::SWORD,
        WeaponType::AXE,
        WeaponType::BOW,
        WeaponType::STAFF,
        WeaponType::SPEAR
    };

    modifierValues = {
        DamageType::Physical,
        DamageType::Fire,
        DamageType::Ice,
        DamageType::Electrical,
        DamageType::Poison,
        DamageType::Holy,
        DamageType::Bloody
    };
}

std::vector<Rarity> enumsToVectorList::GetRarityValues() {
    return rarityValues;
}

std::vector<WeaponPrefix> enumsToVectorList::GetPrefixValues() {
    return prefixValues;
}

std::vector<WeaponType> enumsToVectorList::GetTypeValues() {
    return typeValues;
}

std::vector<DamageType> enumsToVectorList::GetModifierValues() {
    return modifierValues;
}
