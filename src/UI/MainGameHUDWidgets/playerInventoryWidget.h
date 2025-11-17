#ifndef NOTSIMPLEGAME_PLAYERINVENTORYWIDGET_H
#define NOTSIMPLEGAME_PLAYERINVENTORYWIDGET_H
#include "TGUI/Widgets/Panel.hpp"
#include "TGUI/Widgets/Picture.hpp"

class Inventory;

class playerInventoryWidget {
    // Cached
    std::string emptySlotTexturePath = "../src/core/assets/equipment/empty_slot.png";
    std::array<std::string,16> cachedItemTexturePaths;
    // Inventory Icons
    std::array<tgui::Picture::Ptr,16> inventorySlots;
public:
    void initializeIcons(const tgui::Panel::Ptr& parentPanel);

    void UpdateInventory(Inventory& inventoryPlayer);
};


#endif //NOTSIMPLEGAME_PLAYERINVENTORYWIDGET_H