#ifndef NOTSIMPLEGAME_ITEMMANAGER_H
#define NOTSIMPLEGAME_ITEMMANAGER_H
#include <memory>

#include "items/itemBase.h"

class baseEntity;
class player;
class itemBase;
class weapon;

class itemManager {

    std::unique_ptr<itemBase> items = std::make_unique<itemBase>();

    std::vector<std::shared_ptr<itemBase>> ItemDatabase;
    static int nextItemID;
public:
    void CreateItem(int playerLevel, int ID,baseEntity &entity);

    void AddItemToDatabase(const std::shared_ptr<itemBase>& item) {
        ItemDatabase.push_back(item);
    }

};


#endif //NOTSIMPLEGAME_ITEMMANAGER_H