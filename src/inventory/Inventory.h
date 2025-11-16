#ifndef NOTSIMPLEGAME_INVENTORY_H
#define NOTSIMPLEGAME_INVENTORY_H
#include <array>
#include <memory>
#include <vector>

class itemBase;
class player;

struct slot {
    std::shared_ptr<itemBase> item = nullptr;
    bool isOccupied = false;

};

class Inventory {
    std::array<slot, 16> Slots;
public:
    bool AddItem(const std::shared_ptr<itemBase>& item, int index);
    std::shared_ptr<itemBase> RemoveItemToMouse(int index);
    bool DeleteItem(int index);

    void printInventory();

    std::array<slot, 16>& GetSlots() {
        return Slots;
    }
};


#endif //NOTSIMPLEGAME_INVENTORY_H