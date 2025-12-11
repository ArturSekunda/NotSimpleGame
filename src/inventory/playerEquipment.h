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

    void RemoveItemStats(int index,baseStats& P_stats);


};


#endif //NOTSIMPLEGAME_PLAYEREQUIPMENT_H