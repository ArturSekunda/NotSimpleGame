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

enum class WeaponPrefix
{

    Ancient,
    Dark,
    Blazing,
    Frozen,
    Cursed,
    Divine,
    Shadow,
    Crimson,
    Golden,
    Silver,
    Rusted,
    Ethereal,
    Vengeful,
    Storm,
    Blood,
    Dragon,
    Phantom,
    Royal,
    Mystic,
    Demon

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
    Poison
};

#endif //NOTSIMPLEGAME_ITEMENUMS_H