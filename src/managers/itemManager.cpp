#include "itemManager.h"
#include "items/weapon.h"

void itemManager::CreateWeapon(int playerLevel) {
    auto w = weapon::CreateNewWeapon(playerLevel);
    w.DisplayWeaponInfo();

}
