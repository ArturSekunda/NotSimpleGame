#include "itemManager.h"


void itemManager::initialize() {
    EConversion->EnumsToVectorList();
}

void itemManager::CreateWeapon(int playerLevel) {
    auto w = weapon::CreateNewWeapon(playerLevel,
        EConversion->GetPrefix(),
        EConversion->GetType(),
        EConversion->GetModifier(),
        EConversion->GetEValues());
    w.DisplayWeaponInfo();

}
