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
    if (weaponSlot != nullptr) {
        std::cout << "Weapon slot is already occupied!" << std::endl;
        return false;
    }
    weaponSlot = weap;
    return true;
}

bool baseEquipment::EquipArmor(std::shared_ptr<armor> arm) {
    ArmorType type = arm->getArmorType();
    if (armorSlots.at(type) == nullptr) {
        armorSlots[type] = std::move(arm);
        return true;
    }else {
        std::cout << "This armor slot is already occupied!" << std::endl;
        return false;
    }
}

bool baseEquipment::EquipItem(const std::shared_ptr<itemBase>& item,baseEntity& entity) {
    ItemType itemType = item->getItemType();
    switch (itemType) {
        case ItemType::WEAPON: {
            if (std::shared_ptr<weapon> weap = std::dynamic_pointer_cast<weapon>(item)) {
                if (EquipWeapon(weap)) {
                    AddBonusStats(weap->getBonusStats(),entity);
                    weap->DisplayWeaponInfo();
                    return true;
                }
            } else {
                std::cout << "Failed to cast item to weapon!" << std::endl;
                return false;
            }
        }
        case ItemType::ARMOR: {
            if (std::shared_ptr<armor> arm = std::dynamic_pointer_cast<armor>(item)) {
                 if(EquipArmor(arm)) {
                     AddBonusStats(arm->getBonusStats(),entity);
                     arm->DisplayArmorInfo();
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
