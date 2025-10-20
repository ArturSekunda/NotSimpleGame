#ifndef NOTSIMPLEGAME_ITEMENUMS_H
#define NOTSIMPLEGAME_ITEMENUMS_H

enum class Rarity {
    Err_Null,
    COMMON,
    UNCOMMON,
    RARE,
    EPIC,
    LEGENDARY
};

enum class ItemType {
    NONE,
    WEAPON,
    ARMOR,
    CONSUMABLE,
    MISC
};

enum class WeaponType {
    SWORD,
    AXE,
    BOW,
    STAFF,
    SPEAR
};

enum class Prefix
{

    Ancient,
    Dark,
    Blazing,
    Frozen,
    Cursed,
    Divine,
    Shadow,
    Crimson,
    Ethereal,
    Vengeful,
    Storm,
    Dragon,
    Phantom,
    Royal,

};

enum class MaterialTypeOfItem {
    NONE,
    PAPER,
    LEATHER,
    IRON,
    GOLD,
    EMERALD,
    DIAMOND,
};

enum class ArmorType {
    NONE,
    HELMET,
    CHESTPLATE,
    LEGGINGS,
    BOOTS
};

enum class ConsumableType {
    NONE,
    HEALTH_POTION,
    MANA_POTION
};

enum class AccessoryType {
    None,
    Ring,
    Amulet,
    Belt,
};


// Damage Types for weapons and spells

enum class DamageType {
    Physical,
    Magical,
    Electrical,
    Fire,
    Ice,
    Poison,
    Bloody,
    Holy
};

enum class EnchantWeaponType {
    NONE,
    Fire,
    Ice,
    Lightning,
    Poison
};

enum class EnchantArmorType {
    NONE,
    ADDITIONAL_DEFENSE,
    ADDITIONAL_HEALTH,
    ADDITIONAL_MANA
};

#endif //NOTSIMPLEGAME_ITEMENUMS_H