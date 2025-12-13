#include "enumConversionTextures.h"

#include "itemEnums.h"

void enumConversionTextures::RarityToFilepath() {
    RarityTexturePaths = {
        {Rarity::COMMON,  ASSETS_BASE + "rarity/CommonItem.png"},
        {Rarity::UNCOMMON, ASSETS_BASE + "rarity/UnCommonItem.png"},
        {Rarity::RARE, ASSETS_BASE + "rarity/RareItem.png"},
        {Rarity::EPIC, ASSETS_BASE + "rarity/EpicItem.png"},
        {Rarity::LEGENDARY, ASSETS_BASE + "rarity/LegendaryItem.png"},
    };
}
