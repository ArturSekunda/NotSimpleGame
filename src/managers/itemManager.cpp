#include "itemManager.h"
#include "items/weapon.h"

void itemManager::CreateWeapon(int playerLevel, int ID) {
    auto w = weapon::CreateNewWeapon(playerLevel,ID);
    w.DisplayWeaponInfo();
}
