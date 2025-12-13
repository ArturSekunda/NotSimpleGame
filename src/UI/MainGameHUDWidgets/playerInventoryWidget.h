#ifndef NOTSIMPLEGAME_PLAYERINVENTORYWIDGET_H
#define NOTSIMPLEGAME_PLAYERINVENTORYWIDGET_H
#include <utility>

#include "inventory/Inventory.h"
#include "items/itemBase.h"
#include "TGUI/Widgets/Panel.hpp"
#include "TGUI/Widgets/Picture.hpp"

struct MouseContainer;

struct UISlot {
    tgui::Picture::Ptr icon;
    int slotIndex;
    std::string cachedTexturePath;

    const std::string ASSETS_BASE = "assets/";

    void Update(Inventory& inventory) {
        auto& slot = inventory.GetSlots()[slotIndex];
        std::string newPath = slot.isOccupied && slot.item
            ? slot.item->getTexturePath()
            : ASSETS_BASE + "equipment/empty_slot.png";

        if (cachedTexturePath != newPath) {
            cachedTexturePath = newPath;
            icon->getRenderer()->setTexture(tgui::Texture(newPath));
        }
    }
    void Initialize(const tgui::Panel::Ptr& parentPanel, int index) {
        slotIndex = index;
        icon = tgui::Picture::create((ASSETS_BASE + "equipment/empty_slot.png").data());
        if (!icon) {
            throw std::runtime_error("Failed to create inventory slot icon");
        }

        icon->setSize("20%", "20%");
        icon->setPosition(
            (std::to_string(7 + index % 4 * 20) + "%").data(),
            (std::to_string(7 + index / 4 * 20) + "%").data()
        );
        parentPanel->add(icon);
        cachedTexturePath = ASSETS_BASE + "equipment/empty_slot.png";
    }
};

class playerInventoryWidget {
    std::array<UISlot,16> inventoryUISlots;


public:
    void initializeIcons(const tgui::Panel::Ptr& parentPanel);

    void UIInventory(Inventory &inventoryPlayer, MouseContainer &mouse_container);

    void UpdateUISlots(Inventory &inventoryPlayer) {
        for (auto& UISlot: inventoryUISlots) {
            UISlot.Update(inventoryPlayer);
        }
    }


};


#endif //NOTSIMPLEGAME_PLAYERINVENTORYWIDGET_H