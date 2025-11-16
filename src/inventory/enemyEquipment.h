#ifndef NOTSIMPLEGAME_ENEMYEQUIPMENT_H
#define NOTSIMPLEGAME_ENEMYEQUIPMENT_H
#include "baseEquipment.h"


class Inventory;

class enemyEquipment : public baseEquipment {
public:
    void DropEquipmentOnDeath(Inventory& playerInventory);
};


#endif //NOTSIMPLEGAME_ENEMYEQUIPMENT_H