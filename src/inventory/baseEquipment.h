#ifndef NOTSIMPLEGAME_BASEEQUIPMENT_H
#define NOTSIMPLEGAME_BASEEQUIPMENT_H

#include <memory>
#include "items/itemBase.h"
#include "items/armor.h"
#include "items/weapon.h"

class baseEntity;
class player;
class basicEnemy;

class baseEquipment {
protected:
    std::shared_ptr<weapon> weaponSlot;
    std::map<ArmorType, std::shared_ptr<armor>> armorSlots;
public:
    baseEquipment();
    virtual ~baseEquipment() = default;


    bool EquipWeapon(const std::shared_ptr<weapon> &weap, int index);
    bool EquipArmor(std::shared_ptr<armor> arm, int index);
    bool EquipItem(const std::shared_ptr<itemBase> &item, baseEntity &entity, int index);

    static void AddBonusStats(const ItemBonusStats &stats,baseEntity& entity);

    std::map<ArmorType, std::shared_ptr<armor>>& getArmorSlots() {
        return armorSlots;
    }

    std::shared_ptr<weapon> getWeaponSlot() {
        return weaponSlot;
    }





};


#endif //NOTSIMPLEGAME_BASEEQUIPMENT_H
