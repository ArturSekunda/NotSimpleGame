#ifndef NOTSIMPLEGAME_PLAYERINVENTORYWIDGET_H
#define NOTSIMPLEGAME_PLAYERINVENTORYWIDGET_H
#include "inventory/Inventory.h"
#include "items/itemBase.h"
#include "TGUI/Widgets/Panel.hpp"
#include "TGUI/Widgets/Picture.hpp"

struct UISlot {
    tgui::Picture::Ptr icon;
    int slotIndex;
    std::string cachedTexturePath;

    void Update(Inventory& inventory) {
        auto& slot = inventory.GetSlots()[slotIndex];
        std::string newPath = slot.isOccupied && slot.item
            ? slot.item->getTexturePath()
            : "../src/core/assets/equipment/empty_slot.png";

        if (cachedTexturePath != newPath) {
            cachedTexturePath = newPath;
            icon->getRenderer()->setTexture(tgui::Texture(newPath));
        }
    }
    void Initialize(const tgui::Panel::Ptr& parentPanel, int index) {
        slotIndex = index;
        icon = tgui::Picture::create("../src/core/assets/equipment/empty_slot.png");
        if (!icon) {
            throw std::runtime_error("Failed to create inventory slot icon");
        }
        icon->setSize("20%", "20%");
        icon->setPosition(
            (std::to_string(7 + index % 4 * 20) + "%").data(),
            (std::to_string(7 + index / 4 * 20) + "%").data()
        );
        parentPanel->add(icon);
        cachedTexturePath = "../src/core/assets/equipment/empty_slot.png";
    }
    void OnClick(sf::Vector2i mousePos, Inventory& inventoryPlayer) {
        icon->onClick([inventoryPlayer, mousePos,this]() {
            if (cachedTexturePath == "../src/core/assets/equipment/empty_slot.png") {
                std::cout << "Clicked on empty slot at index " << slotIndex << std::endl;
                return;
            }
        });
    }
};

class playerInventoryWidget {
    std::array<UISlot,16> inventoryUISlots;

public:
    void initializeIcons(const tgui::Panel::Ptr& parentPanel);

    void UpdateInventory(Inventory& inventoryPlayer);

    void OnClickItemSlot(Inventory& inventoryPlayer);
};


#endif //NOTSIMPLEGAME_PLAYERINVENTORYWIDGET_H