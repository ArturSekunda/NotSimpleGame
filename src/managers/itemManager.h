#ifndef NOTSIMPLEGAME_ITEMMANAGER_H
#define NOTSIMPLEGAME_ITEMMANAGER_H
#include <memory>
#include "items/itemBase.h"
#include "items/weapon.h"
#include "items/helpers/enumConversion.h"

class player;
class itemBase;
class weapon;
class enumConversion;

class itemManager {

    std::unique_ptr<enumConversion> EConversion = std::make_unique<enumConversion>();
    std::unique_ptr<itemBase> items = std::make_unique<itemBase>();
public:
    void initialize();
    void CreateWeapon(int playerLevel);
};


#endif //NOTSIMPLEGAME_ITEMMANAGER_H