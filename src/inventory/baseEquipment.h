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
    ~baseEquipment() = default;

    // singletone
    static baseEquipment& getInstance() {
        static baseEquipment instance;
        return instance;
    }


    bool EquipWeapon(const std::shared_ptr<weapon> &weap);
    bool EquipArmor(std::shared_ptr<armor> arm);
    bool EquipItem(const std::shared_ptr<itemBase>& item,baseEntity& entity);

    bool UnEquipItem(const std::shared_ptr<itemBase>& item);

    void AddBonusStats(const ItemBonusStats &stats,baseEntity& entity);
    void RemoveBonusStats(const ItemBonusStats &stats,baseEntity& entity);





};


#endif //NOTSIMPLEGAME_BASEEQUIPMENT_H
