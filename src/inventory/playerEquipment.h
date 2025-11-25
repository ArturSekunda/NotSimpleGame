#ifndef NOTSIMPLEGAME_PLAYEREQUIPMENT_H
#define NOTSIMPLEGAME_PLAYEREQUIPMENT_H
#include "baseEquipment.h"
#include "entities/helpers/entityStructs.h"


struct baseStats;

class playerEquipment :  public baseEquipment {
public:
    playerEquipment() = default;
    ~playerEquipment() override = default;

    std::shared_ptr<itemBase> getItemFromSlot(int index);
    void RemoveItem(int index);

    void RemoveItemStats(int index,baseStats& P_stats) {
        switch (getItemFromSlot(index)->getItemType()) {
            case ItemType::WEAPON: {
                if (weaponSlot) {
                    ItemBonusStats stats = weaponSlot->getBonusStats();
                    P_stats.strength -= stats.strength;
                    P_stats.dexterity -= stats.dexterity;
                    P_stats.charisma -= stats.charisma;
                    P_stats.endurance -= stats.endurance;
                    P_stats.intelligence -= stats.intelligence;
                    P_stats.luck -= stats.luck;
                    P_stats.vitality -= stats.vitality;
                }
                break;
            }
            case ItemType::ARMOR: {
                for (const auto& [type, armor] : armorSlots) {
                       if (armor) {
                           ItemBonusStats stats = armor->getBonusStats();
                           P_stats.strength -= stats.strength;
                           P_stats.dexterity -= stats.dexterity;
                           P_stats.charisma -= stats.charisma;
                           P_stats.endurance -= stats.endurance;
                           P_stats.intelligence -= stats.intelligence;
                           P_stats.luck -= stats.luck;
                           P_stats.vitality -= stats.vitality;
                           break;
                       }
                }
            }
            default:
                std::cout << "Item type not equippable!" << std::endl;
                break;
        }

    }


};


#endif //NOTSIMPLEGAME_PLAYEREQUIPMENT_H