#ifndef NOTSIMPLEGAME_ENEMYEQUIPMENT_H
#define NOTSIMPLEGAME_ENEMYEQUIPMENT_H
#include "baseEquipment.h"


class Inventory;

class enemyEquipment : public baseEquipment {
    bool TryAddItemToSlot(Inventory& inventory, std::shared_ptr<itemBase> item);
public:
    void DropEquipmentOnDeath(Inventory& playerInventory);

    void printEquipment();
};


#endif //NOTSIMPLEGAME_ENEMYEQUIPMENT_H