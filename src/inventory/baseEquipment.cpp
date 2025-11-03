#include "baseEquipment.h"
#include "entities/player/player.h"
#include "entities/enemies/basicEnemy.h"

#include <utility>

baseEquipment::baseEquipment() {
    weaponSlot = nullptr;
    armorSlots = {
            {ArmorType::HELMET, nullptr},
            {ArmorType::CHESTPLATE, nullptr},
            {ArmorType::LEGGINGS, nullptr},
            {ArmorType::BOOTS, nullptr},
    };
}

bool baseEquipment::EquipWeapon(const std::shared_ptr<weapon>& weap) {
    weaponSlot = weap;
    return true;
}

bool baseEquipment::EquipArmor(std::shared_ptr<armor> arm) {
    ArmorType type = arm->getArmorType();
    armorSlots[type] = std::move(arm);
    return true;
}

bool baseEquipment::EquipItem(const std::shared_ptr<itemBase>& item) {
    ItemType itemType = item->getItemType();
    switch (itemType) {
        case ItemType::WEAPON: {
            std::shared_ptr<weapon> weap = std::dynamic_pointer_cast<weapon>(item);
            if (weap) {
                if (EquipWeapon(weap)) {
                    AddBonusStats(weap->getBonusStats());
                }
            } else {
                std::cout << "Failed to cast item to weapon!" << std::endl;
                return false;
            }
        }
        case ItemType::ARMOR: {
            std::shared_ptr<armor> arm = std::dynamic_pointer_cast<armor>(item);
            if (arm) {
                 if(EquipArmor(arm)) {
                     AddBonusStats(arm->getBonusStats());
                     return true;
                 }
            } else {
                std::cout << "Failed to cast item to armor!" << std::endl;
                return false;
            }
        }
        default:
            std::cout << "Item type not equippable!" << std::endl;
            return false;
    }
}

void baseEquipment::AddBonusStats(const ItemBonusStats &stats,baseEntity& entity) {



}