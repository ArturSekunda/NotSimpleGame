#include "itemBase.h"

itemBase::itemBase(int id, const std::string &name, const std::string &description, Rarity rarity, int level) : playerRef(nullptr) {
    ItemId = id;
    ItemName = name;
    ItemDescription = description;
    ItemRarity = rarity;
    ItemLevel = level;
}

void itemBase::SetPlayerRef(player *playerPtr) {
    playerRef = playerPtr;
}

std::string itemBase::RarityToString(Rarity rarity) const {
    switch (rarity) {
        case Rarity::Err_Null:
            return "Null";
        case Rarity::COMMON:
            return "Common";
        case Rarity::UNCOMMON:
            return "Uncommon";
        case Rarity::RARE:
            return "Rare";
        case Rarity::EPIC:
            return "Epic";
        case Rarity::LEGENDARY:
            return "Legendary";
        default:
            return "Unknown";
    }
}

std::string itemBase::WeaponPrefixToString(WeaponPrefix prefix) const {
    switch (prefix) {
        case WeaponPrefix::Ancient:
            return "Ancient";
        case WeaponPrefix::Dark:
            return "Dark";
        case WeaponPrefix::Blazing:
            return "Blazing";
        case WeaponPrefix::Frozen:
            return "Frozen";
        case WeaponPrefix::Cursed:
            return "Cursed";
        case WeaponPrefix::Divine:
            return "Divine";
        case WeaponPrefix::Shadow:
            return "Shadow";
        case WeaponPrefix::Crimson:
            return "Crimson";
        case WeaponPrefix::Golden:
            return "Golden";
        case WeaponPrefix::Silver:
            return "Silver";
        case WeaponPrefix::Rusted:
            return "Rusted";
        case WeaponPrefix::Ethereal:
            return "Ethereal";
        case WeaponPrefix::Vengeful:
            return "Vengeful";
        case WeaponPrefix::Storm:
            return "Storm";
        case WeaponPrefix::Blood:
            return "Blood";
        case WeaponPrefix::Dragon:
            return "Dragon";
        case WeaponPrefix::Phantom:
            return "Phantom";
        case WeaponPrefix::Royal:
            return "Royal";
        case WeaponPrefix::Mystic:
            return "Mystic";
        case WeaponPrefix::Demon:
            return "Demon";
        default:
            return "Unknown";
    }
}

std::string itemBase::WeaponTypeToString(WeaponType type) const {
    switch (type) {
        case WeaponType::SWORD:
            return "Sword";
        case WeaponType::AXE:
            return "Axe";
        case WeaponType::BOW:
            return "Bow";
        case WeaponType::STAFF:
            return "Staff";
        case WeaponType::SPEAR:
            return "Spear";
        default:
            return "Unknown";
    }
}

std::string itemBase::DamageTypeToString(DamageType type) const {
    switch (type){
        case DamageType::Physical:
            return "Physical";
        case DamageType::Magical:
            return "Magical";
        case DamageType::Electrical:
            return "Electrical";
        case DamageType::Bloody:
            return "Bloody";
        case DamageType::Fire:
            return "Fire";
        case DamageType::Ice:
            return "Ice";
        case DamageType::Poison:
            return "Poison";
        case DamageType::Holy:
            return "Holy";
        default:
            return "Unknown";
    }
}

float itemBase::RarityToFloatValue(Rarity rarity) const {
    switch (rarity) {
        case Rarity::COMMON:
            return 1.0f;
        case Rarity::UNCOMMON:
            return 1.2f;
        case Rarity::RARE:
            return 1.5f;
        case Rarity::EPIC:
            return 2.0f;
        case Rarity::LEGENDARY:
            return 3.0f;
        default:
            return 0.0f;
    }
}

float itemBase::WeaponTypeToFloatValue(WeaponType type) const {
    switch (type) {
        case WeaponType::SWORD:
            return 1.0f;
        case WeaponType::AXE:
            return 1.1f;
        case WeaponType::BOW:
            return 0.9f;
        case WeaponType::STAFF:
            return 0.8f;
        case WeaponType::SPEAR:
            return 1.0f;
        default:
            return 0.0f;
    }
}

float itemBase::DamageTypeToFloatValue(DamageType type) const {
    switch (type) {
        case DamageType::Physical:
            return 1.0f;
        case DamageType::Magical:
            return 1.2f;
        case DamageType::Electrical:
            return 1.3f;
        case DamageType::Bloody:
            return 1.1f;
        case DamageType::Fire:
            return 1.4f;
        case DamageType::Ice:
            return 1.3f;
        case DamageType::Poison:
            return 1.2f;
        case DamageType::Holy:
            return 1.5f;
        default:
            return 0.0f;
    }
}

float itemBase::WeaponTypeToBaseRange(WeaponType type) const {
    switch (type) {
        case WeaponType::SWORD:
            return 1.5f;
        case WeaponType::AXE:
            return 1.3f;
        case WeaponType::BOW:
            return 5.0f;
        case WeaponType::STAFF:
            return 4.0f;
        case WeaponType::SPEAR:
            return 2.5f;
        default:
            return 0.0f;
    }
}
