#include "itemBase.h"

#include "core/darkMath.h"

void itemBase::GenerateBonusStats(int MaxGeneratedStat, ItemBonusStats& bonusStats) {
    if (MaxGeneratedStat < 1) {
        MaxGeneratedStat = 1;
    }

    auto& dm = darkMath::getInstance();

    int chancePercent = 15 + (MaxGeneratedStat * 15);

    if (dm.generateIntNumber(1, 100) <= chancePercent) {
        bonusStats.strength = dm.generateIntNumber(1, MaxGeneratedStat);
    }
    if (dm.generateIntNumber(1, 100) <= chancePercent) {
        bonusStats.dexterity = dm.generateIntNumber(1, MaxGeneratedStat);
    }
    if (dm.generateIntNumber(1, 100) <= chancePercent) {
        bonusStats.intelligence = dm.generateIntNumber(1, MaxGeneratedStat);
    }
    if (dm.generateIntNumber(1, 100) <= chancePercent) {
        bonusStats.charisma = dm.generateIntNumber(1, MaxGeneratedStat);
    }
    if (dm.generateIntNumber(1, 100) <= chancePercent) {
        bonusStats.endurance = dm.generateIntNumber(1, MaxGeneratedStat);
    }
    if (dm.generateIntNumber(1, 100) <= chancePercent) {
        bonusStats.luck = dm.generateIntNumber(1, MaxGeneratedStat);
    }
    if (dm.generateIntNumber(1, 100) <= chancePercent) {
        bonusStats.vitality = dm.generateIntNumber(1, MaxGeneratedStat);
    }
}

int itemBase::GenerateBonusStatsByRarity(Rarity RR) {
    switch (RR) {
        case Rarity::COMMON: {

            return 1;

        }
        case Rarity::UNCOMMON: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 2);
            return enchantCount;

        }
        case Rarity::RARE: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 3);
            return enchantCount;

        }
        case Rarity::EPIC: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 4);
            return enchantCount;

        }
        case Rarity::LEGENDARY: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 5);
            return enchantCount;

        }
        default:
            std::cout << "No bonusStats (XD)" << "\n";
            return 0;
    }
}
