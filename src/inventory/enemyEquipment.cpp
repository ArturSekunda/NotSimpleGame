#include "enemyEquipment.h"
#include "inventory/Inventory.h"

void enemyEquipment::DropEquipmentOnDeath(Inventory &playerInventory) {
    for (auto& slot: playerInventory.GetSlots()) {
        if (slot.isOccupied == false) {
            if (weaponSlot != nullptr) {
                slot.item = weaponSlot;
                slot.isOccupied = true;
                weaponSlot = nullptr;
                break; // Exit the loop after dropping the weapon
            }
            for (auto& [type, arm] : armorSlots) {
                if (arm != nullptr) {
                    slot.item = arm;
                    slot.isOccupied = true;
                    arm = nullptr;
                    break; // Exit the loop after dropping one armor piece
                }
            }
        }
    }
}
