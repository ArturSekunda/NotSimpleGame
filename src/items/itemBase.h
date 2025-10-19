#ifndef NOTSIMPLEGAME_ITEMBASE_H
#define NOTSIMPLEGAME_ITEMBASE_H
#include <string>
#include "helpers/itemStructs.h"

class player;

class itemBase {
protected: // Attributes

    int ItemId = 0;
    std::string ItemName = "NULL";
    std::string ItemDescription = "NULL";
    Rarity ItemRarity = Rarity::Err_Null;
    int ItemLevel = 0;

public: // Constructors and Destructors

    itemBase() = default;
    itemBase(int id, const std::string &name, const std::string &description, Rarity rarity, int level);
    virtual ~itemBase() = default;


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

};


#endif //NOTSIMPLEGAME_ITEMBASE_H
