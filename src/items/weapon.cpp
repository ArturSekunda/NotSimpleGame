#include "weapon.h"
#include "items/helpers/enumConversion.h"
#include <iostream>
#include <fstream>
#include <string>

#include "core/darkMath.h"

weapon weapon::CreateNewWeapon(int playerLevel, int itemID) {

    weapon newWeapon;

    auto& EC = enumConversion::getInstance();

    // Randomly select Rarity, Prefix, Type, and Modifier
    int HowMuchRare = darkMath::getInstance().generateDistanceDistribution({55,20,15,10,5}) + 1;
    int WPrefix = darkMath::getInstance().UniformIntDistribution(0, static_cast<int>(EC.GetPrefix().size() - 1));
    int Type = darkMath::getInstance().UniformIntDistribution(0, static_cast<int>(EC.GetType().size() - 1));
    int Modifier = darkMath::getInstance().UniformIntDistribution(0, static_cast<int>(EC.GetModifier().size() - 1));
    int Material = darkMath::getInstance().generateDistanceDistribution({55,20,15,10,5,1}) + 1;

    newWeapon.GenerateWeaponStats(playerLevel,static_cast<Rarity>(HowMuchRare), static_cast<WeaponType>(Type), static_cast<DamageType>(Modifier), static_cast<MaterialTypeOfItem>(Material));

    newWeapon.GenerateWeaponName(static_cast<Prefix>(WPrefix),static_cast<Rarity>(HowMuchRare), static_cast<WeaponType>(Type), static_cast<DamageType>(Modifier),static_cast<MaterialTypeOfItem>(Material));

    newWeapon.GenerateWeaponEnchants(static_cast<Rarity>(HowMuchRare));

    newWeapon.ApplyEnchantmentDamage();

    newWeapon.GenerateWeaponBonusStats(static_cast<Rarity>(HowMuchRare));

    newWeapon.setGenItemType(ItemType::WEAPON);
    newWeapon.setId(itemID);

    return newWeapon;
}

void weapon::GenerateWeaponName(Prefix prefix,Rarity rarity, WeaponType type, DamageType damageType, MaterialTypeOfItem material) {

    // Fallback to hardcoded composition
    ItemUUID.ItemName =
        EC.GetRarityNames().at(rarity) + " " +
            EC.GetPrefixNames().at(prefix) + " " +
                EC.GetMaterialNames().at(material) + " " +
                    EC.GetWeaponTypeNames().at(type) + " (" +
                        EC.GetDamageTypeNames().at(damageType) + ")";
}

void weapon::GenerateWeaponStats(int playerLevel,Rarity rarity, WeaponType type, DamageType damageType, MaterialTypeOfItem material) {

    auto WeaponLevel = darkMath::getInstance().generateIntNumber(std::clamp(playerLevel - 2, 1, playerLevel), playerLevel + 1);

    setLevel(WeaponLevel);

    float rarityMultiplier = EC.GetRarityValues().at(rarity);
    float typeMultiplier = EC.GetWTypeValues().at(type);
    float damageTypeMultiplier = EC.GetDamageValues().at(damageType);
    float materialMultiplier = EC.GetMaterialValues().at(material);

    int baseDamage = static_cast<int>(
        (5 + (WeaponLevel * 2.0f)) *
        rarityMultiplier *
        typeMultiplier *
        damageTypeMultiplier *
        materialMultiplier
    );

    float baseAttackSpeed = (0.5f + (2.f / rarityMultiplier));
    float baseRange = EC.GetBaseRange().at(type);

    setDamage(baseDamage);
    setAttackSpeed(baseAttackSpeed);
    setRange(baseRange);

}

void weapon::GenerateWeaponEnchants(Rarity RR) {
    auto EnchantValuesMap = EC.GetEValues();
    switch (RR) {
        case Rarity::COMMON: {

            for (int i = 0; i < 1; i++) {
                auto Enchant = static_cast<EnchantWeaponType>(darkMath::getInstance().generateDistanceDistribution({45,25,15,10,5}));

                GenerateEnchantStruct(Enchant);
            }

        }break;
        case Rarity::UNCOMMON: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 2);
            for (int i = 0; i < enchantCount; i++) {
                auto Enchant = static_cast<EnchantWeaponType>(darkMath::getInstance().generateDistanceDistribution({35,30,20,10,5}));

                GenerateEnchantStruct(Enchant);
            }

        }break;
        case Rarity::RARE: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 3);
            for (int i = 0; i < enchantCount; i++) {
                auto Enchant = static_cast<EnchantWeaponType>(darkMath::getInstance().generateDistanceDistribution({25,30,20,15,10}));

                GenerateEnchantStruct(Enchant);
            }

        }break;
        case Rarity::EPIC: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 4);
            for (int i = 0; i < enchantCount; i++) {
                auto Enchant = static_cast<EnchantWeaponType>(darkMath::getInstance().generateDistanceDistribution({10,20,30,25,15}));

                GenerateEnchantStruct(Enchant);
            }

        }break;
        case Rarity::LEGENDARY: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 5);
            for (int i = 0; i < enchantCount; i++) {
                auto Enchant = static_cast<EnchantWeaponType>(darkMath::getInstance().generateDistanceDistribution({5,15,20,25,35}));

                GenerateEnchantStruct(Enchant);
            }

        }break;
        default:
            std::cout << "No enchants for this rarity" << "\n";
            break;
    }
}

void weapon::GenerateEnchantStruct(EnchantWeaponType EType) {

    if (EType == EnchantWeaponType::NONE) {
        return;
    }

    auto EnchantMap = EC.GetEnchantmentNames();

    EnchantmentWeapon newEnchant;
    newEnchant.name = EnchantMap[EType];
    newEnchant.type = EType;
    newEnchant.power = darkMath::getInstance().generateIntNumber(1, (1+getLevel()/2));
    newEnchant.description = "NULL";

    addEnchant(newEnchant);

}

void weapon::ApplyEnchantmentDamage() {
    auto EnchantValuesMap = EC.GetEValues();

    int totalEnchantDamage = 0;

    for (const auto& enchant : enchants) {
        // Calculate damage bonus from each enchant
        int enchantBonus = static_cast<int>(enchant.power * EnchantValuesMap.at(enchant.type));
        totalEnchantDamage += enchantBonus;
    }

    // Apply all enchantment damage at once to base damage
    int currentDamage = getDamage();
    setDamage(currentDamage + totalEnchantDamage);
}

void weapon::GenerateWeaponBonusStats(Rarity RR) {
    switch (RR) {
        case Rarity::COMMON: {

            GenerateBonusStats(1);

        }break;
        case Rarity::UNCOMMON: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 2);
            GenerateBonusStats(enchantCount);

        }break;
        case Rarity::RARE: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 3);
            GenerateBonusStats(enchantCount);

        }break;
        case Rarity::EPIC: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 4);
            GenerateBonusStats(enchantCount);

        }break;
        case Rarity::LEGENDARY: {

            int enchantCount = darkMath::getInstance().generateIntNumber(1, 5);
            GenerateBonusStats(enchantCount);

        }break;
        default:
            std::cout << "No bonusStats (XD)" << "\n";
            break;
    }
}

void weapon::GenerateWeaponDescription(Prefix WPrefix, Rarity RRT, WeaponType WType, DamageType DT) {
}

void weapon::GenerateEnchantDescription(EnchantWeaponType EType, float EValues) {
}

void weapon::GenerateBonusStats(int MaxGeneratedStat) {
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

void weapon::DisplayWeaponInfo() const {
    std::cout << "====================\n";
    ItemUUID.DisplayUUID();
    std::cout << "Description: " << ItemDescription << "\n";
    std::cout << "Damage: " << damage << "\n";
    std::cout << "Attack Speed: " << attackSpeed << "\n";
    std::cout << "Range: " << range << "\n";
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "Enchantments: \n";
    for (auto& enchant : enchants) {
        std::cout << enchant.name << " " << enchant.power << "\n";
    }
    std::cout << "Bonus Stats: \n";
    std::cout << "Strength: " << bonusStats.strength << "\n";
    std::cout << "Dexterity: " << bonusStats.dexterity << "\n";
    std::cout << "Intelligence: " << bonusStats.intelligence << "\n";
    std::cout << "Charisma: " << bonusStats.charisma << "\n";
    std::cout << "Endurance: " << bonusStats.endurance << "\n";
    std::cout << "Luck: " << bonusStats.luck << "\n";
    std::cout << "Vitality: " << bonusStats.vitality << "\n";
    std::cout << "=======================\n";
}
