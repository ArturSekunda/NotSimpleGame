#ifndef NOTSIMPLEGAME_ITEMMANAGER_H
#define NOTSIMPLEGAME_ITEMMANAGER_H
#include <memory>

#include "items/itemBase.h"

class armor;
class baseEntity;
class player;
class itemBase;
class weapon;

class itemManager {

    std::unique_ptr<itemBase> items = std::make_unique<itemBase>();

    std::vector<std::shared_ptr<itemBase>> ItemDatabase;
    static int WeaponID;
    static int ArmorID;
public:
    itemManager();
    ~itemManager() = default;
    void CreateItem(int playerLevel, int ID,baseEntity &entity);

    static std::shared_ptr<weapon> CreateWeaponForEnemy(int enemyLevel);
    static std::shared_ptr<armor> CreateArmorForEnemy(int enemyLevel);

    void AddItemToDatabase(const std::shared_ptr<itemBase>& item) {
        ItemDatabase.push_back(item);
    }

    void PrintItemDatabase();

};


#endif //NOTSIMPLEGAME_ITEMMANAGER_H