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
        DamageType::Magical,
        DamageType::Electrical,
        DamageType::Fire,
        DamageType::Ice,
        DamageType::Poison,
        DamageType::Bloody,
        DamageType::Holy
    };
    itemTypeList ={
        ItemType::NONE,
        ItemType::WEAPON,
        ItemType::ARMOR,
        ItemType::CONSUMABLE,
        ItemType::MISC
    };
}

void enumConversion::EnumsToValues() {
    EnchantmentValues = {
        {EnchantType::NONE, 0.f},
        {EnchantType::Fire, 1.1f},
        {EnchantType::Ice, 1.2f},
        {EnchantType::Lightning, 1.3f},
        {EnchantType::Poison, 1.5f}
    };
    RarityValues = {
        {Rarity::COMMON, 1.f},
        {Rarity::UNCOMMON, 1.2f},
        {Rarity::RARE, 1.5f},
        {Rarity::EPIC, 1.8f},
        {Rarity::LEGENDARY, 2.5f}
    };
    WTypeValues = {
        {WeaponType::SWORD, 1.f},
        {WeaponType::AXE, 1.1f},
        {WeaponType::BOW, 0.9f},
        {WeaponType::STAFF,0.8f},
        {WeaponType::SPEAR, 1.f}
    };
    DamageValues = {
        {DamageType::Physical, 1.f},
        {DamageType::Magical, 1.2f},
        {DamageType::Electrical, 1.3f},
        {DamageType::Fire, 1.4f},
        {DamageType::Ice, 1.3f},
        {DamageType::Poison, 1.5f},
        {DamageType::Bloody, 2.0f},
        {DamageType::Holy, 1.7f},
        {DamageType::Magical, 1.5f}
    };
    BaseRange = {
        {WeaponType::SWORD, 1.5f},
        {WeaponType::AXE, 1.2f},
        {WeaponType::BOW, 3.0f},
        {WeaponType::STAFF, 2.5f},
        {WeaponType::SPEAR, 2.0f}
    };
}

void enumConversion::EnumsToString() {
    EnchantmentName = {
        {EnchantType::NONE, "NONE"},
        {EnchantType::Fire, "Fire"},
        {EnchantType::Ice, "Ice"},
        {EnchantType::Lightning, "Lightning"},
        {EnchantType::Poison, "Poison"}
    };
    RarityName = {
        {Rarity::COMMON, "Common"},
        {Rarity::UNCOMMON, "Uncommon"},
        {Rarity::RARE, "Rare"},
        {Rarity::EPIC, "Epic"},
        {Rarity::LEGENDARY, "Legendary"}
    };
    PrefixName = {
        {WeaponPrefix::Ancient, "Ancient"},
        {WeaponPrefix::Dark, "Dark"},
        {WeaponPrefix::Blazing, "Blazing"},
        {WeaponPrefix::Frozen, "Frozen"},
        {WeaponPrefix::Cursed, "Cursed"},
        {WeaponPrefix::Divine, "Divine"},
        {WeaponPrefix::Shadow, "Shadow"},
        {WeaponPrefix::Crimson, "Crimson"},
        {WeaponPrefix::Golden, "Golden"},
        {WeaponPrefix::Silver, "Silver"},
        {WeaponPrefix::Rusted, "Rusted"},
        {WeaponPrefix::Ethereal, "Ethereal"},
        {WeaponPrefix::Vengeful, "Vengeful"},
        {WeaponPrefix::Storm, "Storm"},
        {WeaponPrefix::Blood, "Blood"},
        {WeaponPrefix::Dragon, "Dragon"},
        {WeaponPrefix::Phantom, "Phantom"},
        {WeaponPrefix::Royal, "Royal"},
        {WeaponPrefix::Mystic, "Mystic"},
        {WeaponPrefix::Demon, "Demon"}
    };
    WeaponTName = {
        {WeaponType::SWORD, "Sword"},
        {WeaponType::AXE, "Axe"},
        {WeaponType::BOW, "Bow"},
        {WeaponType::STAFF, "Staff"},
        {WeaponType::SPEAR, "Spear"}
    };
    ModifierName = {
        {DamageType::Physical, "Physical"},
        {DamageType::Fire, "Fire"},
        {DamageType::Ice, "Ice"},
        {DamageType::Electrical, "Electrical"},
        {DamageType::Poison, "Poison"},
        {DamageType::Bloody, "Bloody"},
        {DamageType::Holy, "Holy"},
        {DamageType::Magical, "Magical"}
    };
    ItemTypeName = {
        {ItemType::NONE, "NONE"},
        {ItemType::WEAPON, "WEAPON"},
        {ItemType::ARMOR, "ARMOR"},
        {ItemType::CONSUMABLE, "CONSUMABLE"},
        {ItemType::MISC, "MISC"}
    };
}

const std::vector<ItemType> & enumConversion::GetItemType() {
    return itemTypeList;
}

const std::vector<Rarity>& enumConversion::GetRarity() {
    return rarity;
}

const std::vector<WeaponPrefix>& enumConversion::GetPrefix() {
    return prefix;
}

const std::vector<WeaponType>& enumConversion::GetType() {
    return type;
}

const std::vector<DamageType>& enumConversion::GetModifier() {
    return modifier;
}

const std::map<EnchantType, float>& enumConversion::GetEValues() {
    return EnchantmentValues;
}

const std::map<Rarity, float>& enumConversion::GetRarityValues() {
    return RarityValues;
}

const std::map<WeaponType, float>& enumConversion::GetWTypeValues() {
    return WTypeValues;
}

const std::map<DamageType, float>& enumConversion::GetDamageValues() {
    return DamageValues;
}

const std::map<WeaponType, float>& enumConversion::GetBaseRange() {
    return BaseRange;
}

const std::map<EnchantType, std::string>& enumConversion::GetEnchantmentNames() {
    return EnchantmentName;
}

const std::map<Rarity, std::string>& enumConversion::GetRarityNames() {
    return RarityName;
}

const std::map<WeaponPrefix, std::string>& enumConversion::GetPrefixNames() {
    return PrefixName;
}

const std::map<WeaponType, std::string>& enumConversion::GetWeaponTypeNames() {
    return WeaponTName;
}

const std::map<DamageType, std::string>& enumConversion::GetDamageTypeNames() {
    return ModifierName;
}

const std::map<ItemType, std::string> & enumConversion::GetItemTypeNames() {
    return ItemTypeName;
}
