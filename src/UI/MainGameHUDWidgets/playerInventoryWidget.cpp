#include "playerInventoryWidget.h"

#include "inventory/Inventory.h"
#include "UI/helpers/mouseContainer.h"

void playerInventoryWidget::initializeIcons(const tgui::Panel::Ptr &parentPanel) {
    for (int i = 0; i < 16; ++i) {
        inventoryUISlots[i].Initialize(parentPanel, i);
    }
}

void playerInventoryWidget::UIInventory(Inventory &inventoryPlayer, MouseContainer& mouse_container) {
    for (auto& UISlot: inventoryUISlots) {
        UISlot.icon->onClick([&mouse_container, &UISlot, &inventoryPlayer]() {
            auto index = UISlot.slotIndex;
            if (mouse_container.itemPointer == nullptr && inventoryPlayer.getItemFromSlot(index) != nullptr) {
                mouse_container.holdItem(inventoryPlayer.getItemFromSlot(index));
                inventoryPlayer.RemoveItem(index);
                return;
            }
            if (mouse_container.itemPointer != nullptr && inventoryPlayer.getItemFromSlot(index) == nullptr) {
                inventoryPlayer.AddItem(mouse_container.itemPointer, index);
                mouse_container.Clear();
                return;
            }
        });
    }
}



