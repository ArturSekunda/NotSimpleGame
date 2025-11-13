#include "itemManager.h"

#include "entities/baseEntity.h"
#include "inventory/baseEquipment.h"
#include "items/armor.h"
#include "items/weapon.h"

itemManager::itemManager() {
    ArmorID = 0;
    WeaponID = 0;
}

void itemManager::CreateItem(int playerLevel, int ID,baseEntity &entity) {
    std::shared_ptr<weapon> w = std::make_shared<weapon>(weapon::CreateNewWeapon(playerLevel, ID));
    std::shared_ptr<armor> a = std::make_shared<armor>(armor::CreateNewArmor(playerLevel,ID));
    if (w) {
        w->DisplayWeaponInfo();
    }
    if (a) {
        a->DisplayArmorInfo();
    }
}

void itemManager::PrintItemDatabase() {
    int i = 0;
    for (const auto& newclmap: ItemDatabase) {
        std::cout << std::to_string(i) + " ";newclmap->getUUIDString();
    }
}

