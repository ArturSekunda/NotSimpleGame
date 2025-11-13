#ifndef NOTSIMPLEGAME_ENEMYEQUIPMENT_H
#define NOTSIMPLEGAME_ENEMYEQUIPMENT_H
#include "baseEquipment.h"


class enemyEquipment : public baseEquipment {
public:
    void DropEquipmentOnDeath(player& playerRef);
};


#endif //NOTSIMPLEGAME_ENEMYEQUIPMENT_H