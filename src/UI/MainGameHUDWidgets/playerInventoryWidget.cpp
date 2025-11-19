#include "playerInventoryWidget.h"

#include "handlers/eventHandler.h"
#include "inventory/Inventory.h"

void playerInventoryWidget::initializeIcons(const tgui::Panel::Ptr &parentPanel) {
    for (int i = 0; i < 16; ++i) {
        inventoryUISlots[i].Initialize(parentPanel, i);
    }
}

void playerInventoryWidget::UpdateInventory(Inventory &inventoryPlayer) {
    for (auto& UISlot: inventoryUISlots) {
        UISlot.Update(inventoryPlayer);
    }
}

void playerInventoryWidget::OnClickItemSlot(Inventory &inventoryPlayer) {
    for (int i = 0; i < 16; ++i) {
        inventoryUISlots[i].OnClick(eventHandler::getInstance().getMousePosition(), inventoryPlayer);
    }
}