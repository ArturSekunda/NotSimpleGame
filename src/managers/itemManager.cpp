#include "itemManager.h"


void itemManager::initialize() {
    VectorListOfEnums->EnumsToVectorList();
}

void itemManager::CreateWeapon(int playerLevel) {
    weapons->CreateNewWeapon(playerLevel,
        VectorListOfEnums->GetPrefixValues(),
        VectorListOfEnums->GetTypeValues(),
        VectorListOfEnums->GetModifierValues());
}

void itemManager::DisplayItemInfo() const {
    weapons->DisplayWeaponInfo();
}
