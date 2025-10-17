#include "itemManager.h"

void itemManager::GetPlayerRef(player* player) {
    items->SetPlayerRef(player);
}

void itemManager::DisplayItemInfo() const {
    weapons->CreateNewWeapon();
    weapons->DisplayWeaponInfo();
}
