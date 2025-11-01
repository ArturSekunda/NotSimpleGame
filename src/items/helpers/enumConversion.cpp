#include "items/helpers/enumConversion.h"

#include "itemStructs.h"

void enumConversion::EnumsToVectorList() {
    rarity = {
        Rarity::COMMON,
        Rarity::UNCOMMON,
        Rarity::RARE,
        Rarity::EPIC,
        Rarity::LEGENDARY
    };
    prefix = {
        Prefix::Ancient,
        Prefix::Dark,
        Prefix::Blazing,
        Prefix::Frozen,
        Prefix::Cursed,
        Prefix::Divine,
        Prefix::Shadow,
        Prefix::Crimson,
        Prefix::Ethereal,
        Prefix::Vengeful,
        Prefix::Storm,
        Prefix::Dragon,
        Prefix::Phantom,
        Prefix::Royal,
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
    armorList = {
        ArmorType::NONE,
        ArmorType::HELMET,
        ArmorType::CHESTPLATE,
        ArmorType::LEGGINGS,
        ArmorType::BOOTS
    };
    materialList = {
        MaterialTypeOfItem::PAPER,
        MaterialTypeOfItem::LEATHER,
        MaterialTypeOfItem::IRON,
        MaterialTypeOfItem::GOLD,
        MaterialTypeOfItem::EMERALD,
        MaterialTypeOfItem::DIAMOND,
    };
}

void enumConversion::EnumsToValues() {
    EnchantmentValues = {
        {EnchantWeaponType::NONE, 0.f},
        {EnchantWeaponType::Fire, 0.3f},
        {EnchantWeaponType::Ice, 0.4f},
        {EnchantWeaponType::Lightning, 0.5f},
        {EnchantWeaponType::Poison, 0.6f}
    };
    EnchantArmorValues = {
        {EnchantArmorType::NONE, 0.f},
        {EnchantArmorType::ADDITIONAL_HEALTH, 2.f},
        {EnchantArmorType::ADDITIONAL_MANA, 1.5f},
        {EnchantArmorType::ADDITIONAL_DEFENSE, 1.8f},
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
        {DamageType::Poison, 1.4f},
        {DamageType::Bloody, 1.5f},
        {DamageType::Holy, 1.5f},
    };
    BaseRange = {
        {WeaponType::SWORD, 1.5f},
        {WeaponType::AXE, 1.2f},
        {WeaponType::BOW, 3.0f},
        {WeaponType::STAFF, 3.0f},
        {WeaponType::SPEAR, 2.0f}
    };
    ArmorTypeValues = {
        {ArmorType::HELMET, 0.6f},
        {ArmorType::CHESTPLATE, 1.f},
        {ArmorType::LEGGINGS, 0.8f},
        {ArmorType::BOOTS, 0.6f},
    };
    MaterialValues = {
        {MaterialTypeOfItem::PAPER, 0.2f},
        {MaterialTypeOfItem::LEATHER, 0.5f},
        {MaterialTypeOfItem::IRON, 0.8f},
        {MaterialTypeOfItem::GOLD, 1.2f},
        {MaterialTypeOfItem::EMERALD, 2.f},
        {MaterialTypeOfItem::DIAMOND, 2.8f},
    };
}

void enumConversion::EnumsToString() {
    EnchantmentName = {
        {EnchantWeaponType::NONE, "NONE"},
        {EnchantWeaponType::Fire, "Fire"},
        {EnchantWeaponType::Ice, "Ice"},
        {EnchantWeaponType::Lightning, "Lightning"},
        {EnchantWeaponType::Poison, "Poison"}
    };
    EnchantArmorName = {
        {EnchantArmorType::NONE, "NONE"},
        {EnchantArmorType::ADDITIONAL_HEALTH, "Health Boost"},
        {EnchantArmorType::ADDITIONAL_MANA, "Mana Boost"},
        {EnchantArmorType::ADDITIONAL_DEFENSE, "Armor Boost"},
    };
    RarityName = {
        {Rarity::COMMON, "Common"},
        {Rarity::UNCOMMON, "Uncommon"},
        {Rarity::RARE, "Rare"},
        {Rarity::EPIC, "Epic"},
        {Rarity::LEGENDARY, "Legendary"}
    };
    PrefixName = {
        {Prefix::Ancient, "Ancient"},
        {Prefix::Dark, "Dark"},
        {Prefix::Blazing, "Blazing"},
        {Prefix::Frozen, "Frozen"},
        {Prefix::Cursed, "Cursed"},
        {Prefix::Divine, "Divine"},
        {Prefix::Shadow, "Shadow"},
        {Prefix::Crimson, "Crimson"},
        {Prefix::Ethereal, "Ethereal"},
        {Prefix::Vengeful, "Vengeful"},
        {Prefix::Storm, "Storm"},
        {Prefix::Dragon, "Dragon"},
        {Prefix::Phantom, "Phantom"},
        {Prefix::Royal, "Royal"},
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
    ArmorTypeName = {
        {ArmorType::NONE, "NONE"},
        {ArmorType::HELMET, "Helmet"},
        {ArmorType::CHESTPLATE, "Chestplate"},
        {ArmorType::LEGGINGS, "Leggings"},
        {ArmorType::BOOTS, "Boots"}
    };
    MaterialName = {
        {MaterialTypeOfItem::PAPER, "Paper"},
        {MaterialTypeOfItem::LEATHER, "Leather"},
        {MaterialTypeOfItem::IRON, "Iron"},
        {MaterialTypeOfItem::GOLD, "Gold"},
        {MaterialTypeOfItem::EMERALD, "Emerald"},
        {MaterialTypeOfItem::DIAMOND, "Diamond"}
    };
}

const std::vector<ArmorType> & enumConversion::GetArmorType() {
    return armorList;
}

const std::vector<ItemType> & enumConversion::GetItemType() {
    return itemTypeList;
}

const std::vector<Rarity>& enumConversion::GetRarity() {
    return rarity;
}

const std::vector<Prefix>& enumConversion::GetPrefix() {
    return prefix;
}

const std::vector<WeaponType>& enumConversion::GetType() {
    return type;
}

const std::vector<DamageType>& enumConversion::GetModifier() {
    return modifier;
}

const std::vector<MaterialTypeOfItem>& enumConversion::GetMaterial() {
    return materialList;
}

const std::map<EnchantWeaponType, float>& enumConversion::GetEValues() {
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

const std::map<ArmorType, float> & enumConversion::GetArmorTypeValues() {
    return ArmorTypeValues;
}

const std::map<MaterialTypeOfItem, float>& enumConversion::GetMaterialValues() {
    return MaterialValues;
}

const std::map<EnchantArmorType, float> & enumConversion::GetEnchantArmorValues() {
    return EnchantArmorValues;
}

const std::map<EnchantWeaponType, std::string>& enumConversion::GetEnchantmentNames() {
    return EnchantmentName;
}

const std::map<EnchantArmorType, std::string> & enumConversion::GetEnchantArmorNames() {
    return EnchantArmorName;
}

const std::map<Rarity, std::string>& enumConversion::GetRarityNames() {
    return RarityName;
}

const std::map<Prefix, std::string>& enumConversion::GetPrefixNames() {
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

const std::map<ArmorType, std::string> & enumConversion::GetArmorTypeName() {
    return ArmorTypeName;
}
const std::map<MaterialTypeOfItem, std::string> & enumConversion::GetMaterialNames() {
    return MaterialName;
}
