#include "itemBase.h"

itemBase::itemBase(int id, const std::string &name, const std::string &description, Rarity rarity, int level) {
    ItemId = id;
    ItemName = name;
    ItemDescription = description;
    ItemRarity = rarity;
    ItemLevel = level;
}
