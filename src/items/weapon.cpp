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
    const std::vector<DamageType>& VDType) {

    // Randomly select Rarity, Prefix, Type, and Modifier
    int HowMuchRare = darkMath::getInstance().generateDistanceDistribution({0,50,30,15,5});
    int Prefix = darkMath::getInstance().UniformIntDistribution(0, static_cast<int>(VPrefix.size() - 1));
    int Type = darkMath::getInstance().UniformIntDistribution(0, static_cast<int>(VWType.size() - 1));
    int Modifier = darkMath::getInstance().UniformIntDistribution(0,static_cast<int>(VDType.size() - 1));

    GenerateWeaponStats(playerLevel,static_cast<Rarity>(HowMuchRare), static_cast<WeaponType>(Type), static_cast<DamageType>(Modifier));

    GenerateWeaponName(static_cast<WeaponPrefix>(Prefix),static_cast<Rarity>(HowMuchRare), static_cast<WeaponType>(Type), static_cast<DamageType>(Modifier));

    return *this;
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

void weapon::GenerateWeaponEnchants() {
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
    std::cout << "=======================\n";
}
