#include "playerEquipment.h"

std::shared_ptr<itemBase> playerEquipment::getItemFromSlot(int index) {
    switch (index) {
        case 0:
            return weaponSlot;
        case 1:
            return armorSlots[ArmorType::HELMET];
        case 2:
            return armorSlots[ArmorType::CHESTPLATE];
        case 3:
            return armorSlots[ArmorType::LEGGINGS];
        case 4:
            return armorSlots[ArmorType::BOOTS];
        default:
            return nullptr;
    }
}

void playerEquipment::RemoveItem(int index) {
    switch (index) {
        case 0:
            weaponSlot = nullptr;
            break;
        case 1:
            armorSlots[ArmorType::HELMET] = nullptr;
            break;
        case 2:
            armorSlots[ArmorType::CHESTPLATE] = nullptr;
            break;
        case 3:
            armorSlots[ArmorType::LEGGINGS] = nullptr;
            break;
        case 4:
            armorSlots[ArmorType::BOOTS] = nullptr;
            break;
        default:
            break;
    }
}
