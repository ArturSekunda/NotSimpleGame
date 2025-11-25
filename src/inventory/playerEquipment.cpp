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
            std::cout << "Removing weapon from slot" << std::endl;
            weaponSlot = nullptr;
            break;
        case 1:
            std::cout << "Removing HELMET from slot" << std::endl;
            armorSlots[ArmorType::HELMET] = nullptr;
            break;
        case 2:
            std::cout << "Removing CHESTPLATE from slot" << std::endl;
            armorSlots[ArmorType::CHESTPLATE] = nullptr;
            break;
        case 3:
            std::cout << "Removing LEGGINGS from slot" << std::endl;
            armorSlots[ArmorType::LEGGINGS] = nullptr;
            break;
        case 4:
            std::cout << "Removing BOOTS from slot" << std::endl;
            armorSlots[ArmorType::BOOTS] = nullptr;
            break;
        default:
            break;
    }
}