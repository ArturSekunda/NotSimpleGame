#include "Inventory.h"

#include <iostream>

#include "items/itemBase.h"

bool Inventory::AddItem(const std::shared_ptr<itemBase> &item, int index) {
    if (index < 0 || index >= Slots.size()) {
        std::cerr << "Invalid index for adding item: " << index << "\n";
        return false;
    }
    if (!Slots[index].isOccupied) {
        Slots[index].item = item;
        Slots[index].isOccupied = true;
        return true;
    } else {
        std::cerr << "Slot " << index << " is already occupied.\n";
        return false;
    }
}

void Inventory::printInventory() {
    for (const auto& newclmap: Slots) {
        if (newclmap.isOccupied && newclmap.item) {
            std::cout << "================" << "\n";
            std::cout << "Item present in slot.\n";
            newclmap.item->getUUIDString();
            std::cout << "================" << "\n";
        } else {
            std::cout << "Slot is empty.\n";
        }

    }
}
