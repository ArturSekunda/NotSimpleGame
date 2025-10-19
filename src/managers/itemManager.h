#ifndef NOTSIMPLEGAME_ITEMMANAGER_H
#define NOTSIMPLEGAME_ITEMMANAGER_H
#include <memory>
#include "items/itemBase.h"

class player;
class itemBase;
class weapon;

class itemManager {

    std::unique_ptr<itemBase> items = std::make_unique<itemBase>();
public:
    void CreateWeapon(int playerLevel);
};


#endif //NOTSIMPLEGAME_ITEMMANAGER_H