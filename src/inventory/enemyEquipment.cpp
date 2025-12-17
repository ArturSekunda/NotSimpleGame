#include "enemyEquipment.h"
#include "inventory/Inventory.h"
#include "managers/entitiesManager.h"

bool enemyEquipment::TryAddItemToSlot(Inventory &inventory, std::shared_ptr<itemBase> item, entitiesManager& entitiesManager) {
    for (auto& slot: inventory.GetSlots()) {
        if (slot.isOccupied == false) {
            slot.item = item;
            slot.isOccupied = true;
            item = nullptr;
            return true;
        }
    }
    entitiesManager.removeItemFromDatabase(item);
    return false;
}

void enemyEquipment::DropEquipmentOnDeath(Inventory &playerInventory, entitiesManager& entitiesManager) {
    if (weaponSlot != nullptr) {
        TryAddItemToSlot(playerInventory, weaponSlot, entitiesManager);
    }
    for (auto& [type, arm] : armorSlots) {
        if (arm != nullptr) {
            TryAddItemToSlot(playerInventory, arm, entitiesManager);
        }
    }
}

void enemyEquipment::printEquipment() {
    if (weaponSlot) {
        std::cout << "Equipped Weapon:\n";
        weaponSlot->getUUIDString();
    } else {
        std::cout << "No weapon equipped.\n";
    }

    for (const auto& [type, arm] : armorSlots) {
        if (arm) {
            std::cout << "Equipped Armor (" << static_cast<int>(type) << "):\n";
            arm->getUUIDString();
        } else {
            std::cout << "No armor equipped in slot (" << static_cast<int>(type) << ").\n";
        }
    }
}
