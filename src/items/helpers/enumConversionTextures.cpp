#include "enumConversionTextures.h"

#include "itemEnums.h"

void enumConversionTextures::RarityToFilepath() {
    RarityTexturePaths = {
        {Rarity::COMMON, "../src/core/assets/rarity/CommonItem.png"},
        {Rarity::UNCOMMON, "../src/core/assets/rarity/UnCommonItem.png"},
        {Rarity::RARE, "../src/core/assets/rarity/RareItem.png"},
        {Rarity::EPIC, "../src/core/assets/rarity/EpicItem.png"},
        {Rarity::LEGENDARY, "../src/core/assets/rarity/LegendaryItem.png"},
    };
}
