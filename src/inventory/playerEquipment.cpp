#include "playerEquipment.h"

#include "entities/baseEntity.h"


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

void playerEquipment::RemoveItemStats(int index, baseStats& P_stats, baseEntity& entity) {
    switch (index) {
        case 0:
            if (weaponSlot) {
                P_stats.subtractStats(Weapon_cachedBonusStats. toVector());
                Weapon_cachedBonusStats = {0,0,0,0,0,0,0};
            }
            break;
        case 1:
            if (armorSlots[ArmorType::HELMET]) {
                P_stats.subtractStats(Helmet_cachedBonusStats.toVector());
                entity.removeEquippedArmorDefense(armorSlots[ArmorType:: HELMET]->getArmorDefense());
                entity.removeEquippedArmorHealth(armorSlots[ArmorType:: HELMET]->getArmorHealth());
                entity.removeEquippedArmorMana(armorSlots[ArmorType::HELMET]->getArmorMana());
                Helmet_cachedBonusStats = {0,0,0,0,0,0,0};
            }
            break;
        case 2:
            if (armorSlots[ArmorType::CHESTPLATE]) {
                P_stats.subtractStats(Chestplate_cachedBonusStats.toVector());
                entity.removeEquippedArmorDefense(armorSlots[ArmorType::CHESTPLATE]->getArmorDefense());
                entity.removeEquippedArmorHealth(armorSlots[ArmorType::CHESTPLATE]->getArmorHealth());
                entity.removeEquippedArmorMana(armorSlots[ArmorType::CHESTPLATE]->getArmorMana());
                Chestplate_cachedBonusStats = {0,0,0,0,0,0,0};
            }
            break;
        case 3:
            if (armorSlots[ArmorType:: LEGGINGS]) {
                P_stats.subtractStats(Leggings_cachedBonusStats.toVector());
                entity.removeEquippedArmorDefense(armorSlots[ArmorType::LEGGINGS]->getArmorDefense());
                entity.removeEquippedArmorHealth(armorSlots[ArmorType::LEGGINGS]->getArmorHealth());
                entity.removeEquippedArmorMana(armorSlots[ArmorType:: LEGGINGS]->getArmorMana());
                Leggings_cachedBonusStats = {0,0,0,0,0,0,0};
            }
            break;
        case 4:
            if (armorSlots[ArmorType::BOOTS]) {
                P_stats.subtractStats(Boots_cachedBonusStats.toVector());
                entity.removeEquippedArmorDefense(armorSlots[ArmorType::BOOTS]->getArmorDefense());
                entity.removeEquippedArmorHealth(armorSlots[ArmorType::BOOTS]->getArmorHealth());
                entity.removeEquippedArmorMana(armorSlots[ArmorType::BOOTS]->getArmorMana());
                Boots_cachedBonusStats = {0,0,0,0,0,0,0};
            }
            break;
        default:
            std::cout << "Invalid index for removing item stats!" << std::endl;
            break;
    }
}
