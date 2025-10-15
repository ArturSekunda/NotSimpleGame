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

enum class WeaponName {
    // Swords
    RUSTY_SWORD,
    IRON_SWORD,
    STEEL_SWORD,
    SILVER_SWORD,
    KNIGHTS_BLADE,
    FLAME_TONGUE,
    FROST_BLADE,
    EXCALIBUR,
    DRAGON_SLAYER,

    // Axes
    WOODEN_AXE,
    IRON_AXE,
    BATTLE_AXE,
    GREAT_AXE,
    EXECUTIONERS_AXE,
    THUNDER_AXE,
    BERSERKERS_RAGE,

    // Bows
    SHORT_BOW,
    LONG_BOW,
    HUNTING_BOW,
    COMPOSITE_BOW,
    ELVEN_BOW,
    WIND_WALKER,
    SHADOW_STRIKER,

    // Staffs
    WOODEN_STAFF,
    APPRENTICE_STAFF,
    MAGE_STAFF,
    ARCANE_STAFF,
    STAFF_OF_WISDOM,
    STAFF_OF_POWER,
    CELESTIAL_STAFF,
    STAFF_OF_THE_ANCIENTS,

    // Spears
    WOODEN_SPEAR,
    IRON_SPEAR,
    PIKE,
    HALBERD,
    TRIDENT,
    LIGHTNING_LANCE,
    DRAGONSPINE
};

enum class ArmorType {
    HELMET,
    CHESTPLATE,
    LEGGINGS,
    BOOTS,
    SHIELD
};

enum class ConsumableType {
    HEALTH_POTION,
    MANA_POTION
};

enum class SlotType {
    Armor,
    Weapon,
    Accessory
};

enum class ArmorSlotType {
    Helmet,
    Chestplate,
    Leggings,
    Boots
};

enum class AccessoryType {
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

enum class EnchantType {
    NONE,
    Fire,
    Ice,
    Lightning,
    Poison,
    Healing
};

#endif //NOTSIMPLEGAME_ITEMENUMS_H