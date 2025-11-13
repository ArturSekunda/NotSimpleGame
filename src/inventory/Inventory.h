#ifndef NOTSIMPLEGAME_INVENTORY_H
#define NOTSIMPLEGAME_INVENTORY_H
#include <array>
#include <memory>

class itemBase;
class player;

class Inventory {
    std::array<std::shared_ptr<itemBase>, 16> items;
public:
    bool AddItem(const std::shared_ptr<itemBase>& item, int index);
    std::shared_ptr<itemBase> RemoveItem(int index);
    bool DeleteItem(int index);

};


#endif //NOTSIMPLEGAME_INVENTORY_H