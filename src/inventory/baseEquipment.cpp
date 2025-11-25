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

// Equip weapon to the weapon slot
bool baseEquipment::EquipWeapon(const std::shared_ptr<weapon>& weap, int index) {
    if (weaponSlot != nullptr) {
        std::cout << "Weapon slot is already occupied!" << std::endl;
        return false;
    }
    if (index != 0) {
        std::cout << "Invalid index for weapon slot!" << std::endl;
        return false;
    }
    weaponSlot = weap;
    return true;
}

// Equip armor to the appropriate slot
bool baseEquipment::EquipArmor(std::shared_ptr<armor> arm, int index) {
    ArmorType type = arm->getArmorType();

    switch (index) {
        case 1:
            if (type != ArmorType::HELMET) {
                std::cout << "Armor type does not match helmet slot!" << std::endl;
                return false;
            }else {
                armorSlots[ArmorType::HELMET] = arm;
                return true;
            }
        case 2:
            if (type != ArmorType::CHESTPLATE) {
                std::cout << "Armor type does not match chestplate slot!" << std::endl;
                return false;
            }else {
                armorSlots[ArmorType::CHESTPLATE] = arm;
                return true;
            }
        case 3:
            if (type != ArmorType::LEGGINGS) {
                std::cout << "Armor type does not match leggings slot!" << std::endl;
                return false;
            }else {
                armorSlots[ArmorType::LEGGINGS] = arm;
                return true;
            }
        case 4:
            if (type != ArmorType::BOOTS) {
                std::cout << "Armor type does not match boots slot!" << std::endl;
                return false;
            }else {
                armorSlots[ArmorType::BOOTS] = arm;
                return true;
            }
        default:
            return false;
    }
}

// Equip item to the appropriate slot and add bonus stats to the entity
bool baseEquipment::EquipItem(const std::shared_ptr<itemBase>& item,baseEntity& entity, int index) {
    ItemType itemType = item->getItemType();
    switch (itemType) {
        case ItemType::WEAPON: {
            if (std::shared_ptr<weapon> weap = std::dynamic_pointer_cast<weapon>(item)) {
                if (EquipWeapon(weap, index)) {
                    AddBonusStats(weap->getBonusStats(),entity);
                    //weap->DisplayWeaponInfo();
                    return true;
                }else {
                    return false;
                }
            } else {
                std::cout << "Failed to cast item to weapon!" << std::endl;
                return false;
            }
        }
        case ItemType::ARMOR: {
            if (std::shared_ptr<armor> arm = std::dynamic_pointer_cast<armor>(item)) {
                 if(EquipArmor(arm, index)) {
                     AddBonusStats(arm->getBonusStats(),entity);
                     //arm->DisplayArmorInfo();
                     return true;
                 }else {
                     return false;
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

// Add bonus stats to the entity based on its type
void baseEquipment::AddBonusStats(const ItemBonusStats &stats,baseEntity& entity) {
    switch (entity.getEntityID().type) {
        case EntityType::PLAYER: {
            auto& p = dynamic_cast<player&>(entity);
            p.getStats().addStrength(stats.strength);
            p.getStats().addCharisma(stats.charisma);
            p.getStats().addDexterity(stats.dexterity);
            p.getStats().addIntelligence(stats.intelligence);
            p.getStats().addVitality(stats.vitality);
            p.getStats().addEndurance(stats.endurance);
            p.getStats().addLuck(stats.luck);
            break;
        }
        case EntityType::BASIC_ENEMY: {
            auto& enemy = dynamic_cast<basicEnemy&>(entity);
            enemy.getStats().addStrength(stats.strength);
            enemy.getStats().addCharisma(stats.charisma);
            enemy.getStats().addDexterity(stats.dexterity);
            enemy.getStats().addIntelligence(stats.intelligence);
            enemy.getStats().addVitality(stats.vitality);
            enemy.getStats().addEndurance(stats.endurance);
            enemy.getStats().addLuck(stats.luck);
            break;
        }
        default:
            std::cout << "Entity type not supported for bonus stats!" << std::endl;
            break;
    }
}
