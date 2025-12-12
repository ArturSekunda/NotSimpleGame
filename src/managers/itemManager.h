#ifndef NOTSIMPLEGAME_ITEMMANAGER_H
#define NOTSIMPLEGAME_ITEMMANAGER_H
#include <memory>

#include "items/itemBase.h"

class basicEnemy;
class armor;
class baseEntity;
class player;
class itemBase;
class weapon;

class itemManager {

    std::unique_ptr<itemBase> items = std::make_unique<itemBase>();

    std::vector<std::shared_ptr<itemBase>> ItemDatabase;
    inline static int WeaponID = 0;
    inline static int ArmorID = 0;
public:
    itemManager() = default;
    ~itemManager() = default;

    void CreateWeaponForEnemy(basicEnemy& enemy);
    void CreateArmorForEnemy(basicEnemy& enemy);

    void CreateFirstWeaponForPlayer(player& player);

    void AddItemToDatabase(const std::shared_ptr<itemBase>& item) {
        ItemDatabase.push_back(item);
    }

    void PrintItemDatabase();

};


#endif //NOTSIMPLEGAME_ITEMMANAGER_H