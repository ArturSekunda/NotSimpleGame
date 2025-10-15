#include "weapon.h"

weapon::weapon(int id, const std::string &name, const std::string &description, Rarity rarity, int level,
    WeaponType weapType, int damage, float attackSpeed, float range) :
    itemBase(id, name, description, rarity, level),
    weapType(weapType), damage(damage), attackSpeed(attackSpeed), range(range) {

    // Bruh

}
