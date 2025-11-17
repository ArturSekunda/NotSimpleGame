#include "playerInventoryWidget.h"
#include "inventory/Inventory.h"
#include "items/itemBase.h"
#include <filesystem>

void playerInventoryWidget::initializeIcons(const tgui::Panel::Ptr &parentPanel) {
    for (int i = 0; i < 16; ++i) {
        inventorySlots[i] = tgui::Picture::create("../src/core/assets/equipment/empty_slot.png");
        if (!inventorySlots[i]) {
            throw std::runtime_error("Failed to create inventory slot icon");
        }
        inventorySlots[i]->setSize("20%", "20%");
        inventorySlots[i]->setPosition(
            (std::to_string(7 + i % 4 * 20) + "%").data(),
            (std::to_string(7 + i / 4 * 20) + "%").data()
        );
        parentPanel->add(inventorySlots[i]);
    }
    cachedItemTexturePaths.fill(emptySlotTexturePath);
}

void playerInventoryWidget::UpdateInventory(Inventory &inventoryPlayer) {
    int index = 0;
    for (auto& slot: inventoryPlayer.GetSlots()) {
        std::string newTexturePath;

        if (slot.isOccupied && slot.item && !slot.item->getTexturePath().empty()) {
            newTexturePath = slot.item->getTexturePath();
        } else {
            newTexturePath = emptySlotTexturePath;
        }

        if (cachedItemTexturePaths[index] != newTexturePath) {
            cachedItemTexturePaths[index] = newTexturePath;
            inventorySlots[index]->getRenderer()->setTexture(tgui::Texture(newTexturePath));
        }
        index++;
    }
}