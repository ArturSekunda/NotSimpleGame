#ifndef NOTSIMPLEGAME_WEAPON_H
#define NOTSIMPLEGAME_WEAPON_H
#include "itemBase.h"

class weapon : public itemBase {
protected:
    WeaponType weapType = WeaponType::SWORD;
    int damage = 0;
    float attackSpeed = 0.f;
    float range = 0.f;
public:
    weapon() = default;
    weapon(int id, const std::string &name, const std::string &description, Rarity rarity, int level,
           WeaponType weapType, int damage, float attackSpeed, float range);
    ~weapon() override = default;
};


#endif //NOTSIMPLEGAME_WEAPON_H