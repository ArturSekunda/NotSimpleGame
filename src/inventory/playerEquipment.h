#ifndef NOTSIMPLEGAME_PLAYEREQUIPMENT_H
#define NOTSIMPLEGAME_PLAYEREQUIPMENT_H
#include "baseEquipment.h"


class playerEquipment :  public baseEquipment {
public:
    playerEquipment() = default;
    ~playerEquipment() override = default;

    std::shared_ptr<itemBase> getItemFromSlot(int index);
    void RemoveItem(int index);

};


#endif //NOTSIMPLEGAME_PLAYEREQUIPMENT_H