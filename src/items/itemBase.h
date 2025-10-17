#ifndef NOTSIMPLEGAME_ITEMBASE_H
#define NOTSIMPLEGAME_ITEMBASE_H
#include <string>
#include "itemStructs.h"

class player;

class itemBase {
protected: // Attributes
    int ItemId = 0;
    std::string ItemName = "NULL";
    std::string ItemDescription = "NULL";
    Rarity ItemRarity = Rarity::Err_Null;
    int ItemLevel = 0;

    // Temp
    player* playerRef;

public: // Constructors and Destructors

    itemBase() = default;
    itemBase(int id, const std::string &name, const std::string &description, Rarity rarity, int level);
    virtual ~itemBase() = default;

    void SetPlayerRef(player *playerPtr);

public: // Getters
    int getId() const {
        return ItemId;
    }

    std::string getName() const {
        return ItemName;
    }

    std::string getDescription() const {
        return ItemDescription;
    }

    Rarity getRarity() const {
        return ItemRarity;
    }

    int getLevel() const {
        return ItemLevel;
    }
public: // Setters
    void setId(int id) {
        ItemId = id;
    }

    void setName(const std::string &name) {
        ItemName = name;
    }

    void setDescription(const std::string &description) {
        ItemDescription = description;
    }

    void setRarity(Rarity rarity) {
        ItemRarity = rarity;
    }

    void setLevel(int level) {
        ItemLevel = level;
    }

public: // From Enum to String

    std::string RarityToString(Rarity rarity) const;
    std::string WeaponPrefixToString(WeaponPrefix prefix) const;
    std::string WeaponTypeToString(WeaponType type) const;
    std::string DamageTypeToString(DamageType type) const;

public: // From Enum to Float Value

    float RarityToFloatValue(Rarity rarity) const;
    float WeaponTypeToFloatValue(WeaponType type) const;
    float DamageTypeToFloatValue(DamageType type) const;

    float WeaponTypeToBaseRange(WeaponType type) const;

public: // Vectors for enums

    std::vector<Rarity> rarityValues = {
        Rarity::COMMON,
        Rarity::UNCOMMON,
        Rarity::RARE,
        Rarity::EPIC,
        Rarity::LEGENDARY
    };

    std::vector<WeaponPrefix> prefixValues = {
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

    std::vector<WeaponType> typeValues = {
        WeaponType::SWORD,
        WeaponType::AXE,
        WeaponType::BOW,
        WeaponType::STAFF,
        WeaponType::SPEAR
    };

    std::vector<DamageType> modifierValues = {
        DamageType::Physical,
        DamageType::Fire,
        DamageType::Ice,
        DamageType::Electrical,
        DamageType::Poison,
        DamageType::Holy,
        DamageType::Bloody
    };

};


#endif //NOTSIMPLEGAME_ITEMBASE_H
