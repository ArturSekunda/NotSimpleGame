#ifndef NOTSIMPLEGAME_WEAPON_H
#define NOTSIMPLEGAME_WEAPON_H
#include "itemBase.h"
#include "vector"

class darkMath;
class enumConversion;

class weapon : public itemBase {
protected:
    WeaponType weapType = WeaponType::SWORD;
    int damage = 0;
    float attackSpeed = 0.f;
    float range = 0.f;

    ItemBonusStats bonusStats;
    std::vector<EnchantmentWeapon> enchants;

public:
    weapon() = default;
    ~weapon() override = default;

    // OverLoads
   static weapon CreateNewWeapon(int playerLevel,int itemID);

    std::vector<int> GetWeaponEnchantProbabilities(Rarity RR);

    void GenerateEnchants(Rarity RR, std::vector<int> chanceDistance);

    void GenerateWeaponName(Prefix prefix,Rarity rarity, WeaponType type, DamageType damageType, MaterialTypeOfItem material);

    void GenerateWeaponStats(int playerLevel,Rarity rarity, WeaponType type, DamageType damageType, MaterialTypeOfItem material);

    void GenerateEnchantStruct(EnchantWeaponType EType);

    void ApplyEnchantmentDamage();

    void GenerateWeaponDescription(Prefix WPrefix,Rarity RRT, WeaponType WType, DamageType DT);

    void GenerateEnchantDescription(EnchantWeaponType EType,float EValues);

    void GenerateBonusStats(Rarity RR);

    void DisplayWeaponInfo() const;


public: // Getters and Setters

    void setDamage(int dmg) { damage = dmg; }
    void setAttackSpeed(float atkSpd) { attackSpeed = atkSpd; }
    void setRange(float rng) { range = rng; }
    void setWeaponType(WeaponType type) { weapType = type; }
    void setBonusStats(const ItemBonusStats& stats) { bonusStats = stats; }
    void addEnchant(const EnchantmentWeapon &enchant) { enchants.push_back(enchant); }

    int getDamage() const { return damage; }
    float getAttackSpeed() const { return attackSpeed; }
    float getRange() const { return range; }
    WeaponType getWeaponType() const { return weapType; }
    ItemBonusStats getBonusStats() const { return bonusStats; }
    std::vector<EnchantmentWeapon> getEnchants() const { return enchants; }
};


#endif //NOTSIMPLEGAME_WEAPON_H