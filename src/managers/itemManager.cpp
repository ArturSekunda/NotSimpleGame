#include "itemManager.h"

#include "items/armor.h"
#include "items/weapon.h"

void itemManager::CreateItem(int playerLevel, int ID) {
    auto w = weapon::CreateNewWeapon(playerLevel,ID);
    w.DisplayWeaponInfo();
    auto a = armor::GenerateNewArmor(playerLevel,ID);
    a.DisplayArmorInfo();
}
