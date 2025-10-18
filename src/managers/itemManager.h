#ifndef NOTSIMPLEGAME_ITEMMANAGER_H
#define NOTSIMPLEGAME_ITEMMANAGER_H
#include <memory>
#include "items/itemBase.h"
#include "items/weapon.h"
#include "items/helpers/enumsToVectorList.h"

class player;
class itemBase;
class weapon;
class enumsToVectorList;

class itemManager {

    std::unique_ptr<enumsToVectorList> VectorListOfEnums = std::make_unique<enumsToVectorList>();
    std::unique_ptr<itemBase> items = std::make_unique<itemBase>();
    std::unique_ptr<weapon> weapons = std::make_unique<weapon>();
public:
    void initialize();
    void CreateWeapon(int playerLevel);
    void DisplayItemInfo() const;
};


#endif //NOTSIMPLEGAME_ITEMMANAGER_H