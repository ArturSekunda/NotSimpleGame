#include "itemManager.h"


void itemManager::initialize() {
    EConversion->EnumsToVectorList();
}

void itemManager::CreateWeapon(int playerLevel) {
    weapons->CreateNewWeapon(playerLevel,
        EConversion->GetPrefix(),
        EConversion->GetType(),
        EConversion->GetModifier());
}

void itemManager::DisplayItemInfo() const {
    weapons->DisplayWeaponInfo();
}
