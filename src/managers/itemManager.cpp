#include "itemManager.h"

#include "inventory/baseEquipment.h"
#include "items/armor.h"
#include "items/weapon.h"

void itemManager::CreateItem(int playerLevel, int ID,baseEntity &entity) {
    std::shared_ptr<weapon> w = std::make_shared<weapon>(weapon::CreateNewWeapon(playerLevel, ID));
    std::shared_ptr<armor> a = std::make_shared<armor>(armor::CreateNewArmor(playerLevel,ID));

    baseEquipment::getInstance().EquipItem(w,entity);
    baseEquipment::getInstance().EquipItem(a,entity);
}

