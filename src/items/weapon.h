#ifndef NOTSIMPLEGAME_WEAPON_H
#define NOTSIMPLEGAME_WEAPON_H
#include "itemBase.h"

class darkMath;
class player;

class weapon : public itemBase {
protected:
    WeaponType weapType = WeaponType::SWORD;
    int damage = 0;
    float attackSpeed = 0.f;
    float range = 0.f;

    ItemBonusStats bonusStats;
    std::vector<EnchantType> enchants;

public:
    weapon() = default;
    weapon(int id, const std::string &name, const std::string &description, Rarity rarity, int level,
           WeaponType weapType, int damage, float attackSpeed, float range);
    ~weapon() override = default;

    // OverLoads
    weapon CreateNewWeapon();
    void CreateNewWeapon(WeaponType type);
    void CreateNewWeapon(WeaponType type, Rarity rarity);
    void CreateNewWeapon(int level);
    void CreateNewWeapon(int Damage, float AttackSpeed, float Range);
    void CreateNewWeapon(ItemBonusStats bonusStats, std::vector<EnchantType> enchants);

    void GenerateWeaponName();

    void GenerateWeaponStats(Rarity rarity, WeaponType type, DamageType damageType);

    void GenerateWeaponEnchants();

    void GenerateWeaponBonusStats();

    void DisplayWeaponInfo() const;


public: // Getters and Setters

    void setDamage(int dmg) { damage = dmg; }
    void setAttackSpeed(float atkSpd) { attackSpeed = atkSpd; }
    void setRange(float rng) { range = rng; }
    void setWeaponType(WeaponType type) { weapType = type; }
    void setBonusStats(const ItemBonusStats& stats) { bonusStats = stats; }
    void addEnchant(EnchantType enchant) { enchants.push_back(enchant); }

    int getDamage() const { return damage; }
    float getAttackSpeed() const { return attackSpeed; }
    float getRange() const { return range; }
    WeaponType getWeaponType() const { return weapType; }
    ItemBonusStats getBonusStats() const { return bonusStats; }
    std::vector<EnchantType> getEnchants() const { return enchants; }
};


#endif //NOTSIMPLEGAME_WEAPON_H