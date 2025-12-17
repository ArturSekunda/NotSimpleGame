#ifndef NOTSIMPLEGAME_ENEMYEQUIPMENT_H
#define NOTSIMPLEGAME_ENEMYEQUIPMENT_H
#include "baseEquipment.h"


class entitiesManager;
class Inventory;

class enemyEquipment : public baseEquipment {
    bool TryAddItemToSlot(Inventory& inventory, std::shared_ptr<itemBase> item, entitiesManager& entitiesManager);
public:
    void DropEquipmentOnDeath(Inventory& playerInventory, entitiesManager& entitiesManager);

    void printEquipment();
};


#endif //NOTSIMPLEGAME_ENEMYEQUIPMENT_H