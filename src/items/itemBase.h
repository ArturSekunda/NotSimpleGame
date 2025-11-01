#ifndef NOTSIMPLEGAME_ITEMBASE_H
#define NOTSIMPLEGAME_ITEMBASE_H
#include <string>
#include "helpers/itemStructs.h"

class player;

class itemBase {
protected: // Attributes

    UUID ItemUUID;
    std::string ItemDescription = "NULL";
    Rarity ItemRarity = Rarity::Err_Null;
protected: // Fuctions for child classes

    virtual void GenerateBonusStats(int MaxGeneratedStat, ItemBonusStats& bonusStats);

    virtual int GenerateBonusStatsByRarity(Rarity RR);

public: // Constructors and Destructors

    itemBase() = default;
    virtual ~itemBase() = default;


public: // Getters
    int getId() const {
        return ItemUUID.id;
    }

    std::string getName() const {
        return ItemUUID.ItemName;
    }

    std::string getDescription() const {
        return ItemDescription;
    }

    Rarity getRarity() const {
        return ItemRarity;
    }

    int getLevel() const {
        return ItemUUID.ItemLevel;
    }
    ItemType getItemType() {
        return ItemUUID.ItemType;
    }
public: // Setters
    void setId(int id) {
        ItemUUID.id = id;
    }

    void setName(const std::string &name) {
        ItemUUID.ItemName = name;
    }

    void setDescription(const std::string &description) {
        ItemDescription = description;
    }

    void setRarity(Rarity rarity) {
        ItemRarity = rarity;
    }

    void setLevel(int level) {
        ItemUUID.ItemLevel = level;
    }
    void setGenItemType(ItemType type) {
        ItemUUID.ItemType = type;
    }

};


#endif //NOTSIMPLEGAME_ITEMBASE_H
