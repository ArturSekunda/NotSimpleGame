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

bool Inventory::RemoveItem(int index) {
    if (Slots[index].isOccupied == true) {
        Slots[index].isOccupied = false;
        Slots[index].item = nullptr;
        return true;
    }else {
        std::cerr << "Slot " << index << " is already empty.\n";
        return false;
    }
}

std::shared_ptr<itemBase>  Inventory::getItemFromSlot(int index) {
    if (index < 0 || index >= Slots.size()) {
        return nullptr;
    }
    if (Slots[index].isOccupied) {
        return Slots[index].item;
    }
    return nullptr;
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
