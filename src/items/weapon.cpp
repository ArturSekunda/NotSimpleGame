#include "weapon.h"
#include "entities/player/player.h"
#include <iostream>
#include <fstream>
#include <string>

#include "core/darkMath.h"

weapon::weapon(int id, const std::string &name, const std::string &description, Rarity rarity, int level,
    WeaponType weapType, int damage, float attackSpeed, float range) :
    itemBase(id, name, description, rarity, level),
    weapType(weapType), damage(damage), attackSpeed(attackSpeed), range(range) {

    // Bruh

}

weapon weapon::CreateNewWeapon(int playerLevel,
    const std::vector<WeaponPrefix>& VPrefix,
    const std::vector<WeaponType>& VWType,
    const std::vector<DamageType>& VDType,
    std::map<EnchantType,float> EValues) {
    weapon newWeapon;
    enchants.clear();
    damage = 0;

    // Randomly select Rarity, Prefix, Type, and Modifier
    int HowMuchRare = darkMath::getInstance().generateDistanceDistribution({0,55,20,15,10,5});
    int Prefix = darkMath::getInstance().UniformIntDistribution(0, static_cast<int>(VPrefix.size() - 1));
    int Type = darkMath::getInstance().UniformIntDistribution(0, static_cast<int>(VWType.size() - 1));
    int Modifier = darkMath::getInstance().UniformIntDistribution(0,static_cast<int>(VDType.size() - 1));

    std::cout << "Rarity: " << HowMuchRare << "\n";

    GenerateWeaponStats(playerLevel,static_cast<Rarity>(HowMuchRare), static_cast<WeaponType>(Type), static_cast<DamageType>(Modifier));

    GenerateWeaponName(static_cast<WeaponPrefix>(Prefix),static_cast<Rarity>(HowMuchRare), static_cast<WeaponType>(Type), static_cast<DamageType>(Modifier));

    GenerateWeaponEnchants(static_cast<Rarity>(HowMuchRare), EValues);

    return newWeapon;
}

void weapon::GenerateWeaponName(WeaponPrefix prefix,Rarity rarity, WeaponType type, DamageType damageType) {

    // Fallback to hardcoded composition
    ItemName = RarityToString(rarity) + " " + WeaponPrefixToString(prefix) + " " + WeaponTypeToString(type) + " (" + DamageTypeToString(damageType) + ")";
}

void weapon::GenerateWeaponStats(int playerLevel,Rarity rarity, WeaponType type, DamageType damageType) {

    auto WeaponLevel = darkMath::getInstance().generateIntNumber(std::clamp(playerLevel - 2, 1, playerLevel), playerLevel + 1);

    setLevel(WeaponLevel);

    float rarityMultiplier = RarityToFloatValue(rarity);
    float typeMultiplier = WeaponTypeToFloatValue(type);
    float damageTypeMultiplier = DamageTypeToFloatValue(damageType);

    int baseDamage = static_cast<int>((10 + (WeaponLevel * 1.7f)) * rarityMultiplier * typeMultiplier * damageTypeMultiplier);
    float baseAttackSpeed = (0.5f + (2.f / rarityMultiplier));
    float baseRange = WeaponTypeToBaseRange(type);

    setDamage(baseDamage);
    setAttackSpeed(baseAttackSpeed);
    setRange(baseRange);

}

void weapon::GenerateWeaponEnchants(Rarity RR, std::map<EnchantType,float> EValues) {
    switch (RR) {
        case Rarity::COMMON: {

            auto Enchant = static_cast<EnchantType>(darkMath::getInstance().generateDistanceDistribution({45,25,15,10,5}));
            auto EnchantValue = EValues[Enchant];

            GenerateEnchantStruct(EnchantValue, Enchant);

        }break;
        case Rarity::UNCOMMON: {

            auto Enchant = static_cast<EnchantType>(darkMath::getInstance().generateDistanceDistribution({35,30,20,10,5}));
            auto EnchantValue = EValues[Enchant];

            GenerateEnchantStruct(EnchantValue, Enchant);

        }break;
        case Rarity::RARE: {

            auto Enchant = static_cast<EnchantType>(darkMath::getInstance().generateDistanceDistribution({25,30,20,15,10}));
            auto EnchantValue = EValues[Enchant];

            GenerateEnchantStruct(EnchantValue, Enchant);

        }break;
        case Rarity::EPIC: {

            auto Enchant = static_cast<EnchantType>(darkMath::getInstance().generateDistanceDistribution({10,20,30,25,15}));
            auto EnchantValue = EValues[Enchant];

            GenerateEnchantStruct(EnchantValue, Enchant);
        }break;
        case Rarity::LEGENDARY: {

            auto Enchant = static_cast<EnchantType>(darkMath::getInstance().generateDistanceDistribution({5,15,20,25,35}));
            auto EnchantValue = EValues[Enchant];

            GenerateEnchantStruct(EnchantValue, Enchant);
        }break;
        default:
            std::cout << "No enchants for this rarity" << "\n";
            break;
    }
}

void weapon::GenerateEnchantStruct(float EValues, EnchantType EType) {
    Enchantment newEnchant;
    newEnchant.name = EnchantTypeToString(EType);
    newEnchant.type = EType;
    if (EType != EnchantType::NONE) {
        newEnchant.power = darkMath::getInstance().generateIntNumber(1, (1+getLevel()/2));
    }else {
        newEnchant.power = 0;
    }
    newEnchant.description = "NULL";

    int oldDamage = getDamage();
    int newDamage = static_cast<int>(oldDamage + (newEnchant.power * EValues));

    setDamage(newDamage);
    enchants.push_back(newEnchant);
}

void weapon::GenerateWeaponBonusStats() {
}

void weapon::GenerateWeaponDescription(WeaponPrefix WPrefix, Rarity RRT, WeaponType WType, DamageType DT) {
}

void weapon::DisplayWeaponInfo() const {
    std::cout << ItemName << "\n";
    std::cout << "Description: " << ItemDescription << "\n";
    std::cout << "Damage: " << damage << "\n";
    std::cout << "Attack Speed: " << attackSpeed << "\n";
    std::cout << "Range: " << range << "\n";
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "Enchantments: \n";
    for (auto& enchant : enchants) {
        std::cout << enchant.name << " " << enchant.power << "\n";
    }
    std::cout << "=======================\n";
}
