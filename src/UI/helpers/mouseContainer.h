#ifndef NOTSIMPLEGAME_MOUSECONTAINER_H
#define NOTSIMPLEGAME_MOUSECONTAINER_H
#include "handlers/eventHandler.h"
#include "TGUI/Widgets/Panel.hpp"
#include "items/itemBase.h"

struct MouseContainer {
    std::shared_ptr<itemBase> itemPointer = nullptr;
    tgui::Picture::Ptr weaponPicture = nullptr;

    void Initialize(const tgui::Panel::Ptr &parentPanel) {
        weaponPicture = tgui::Picture::create();
        if (!weaponPicture) {
            throw std::runtime_error("Failed to create mouse container picture");
        }
        weaponPicture->setSize("0%", "0%");
        parentPanel->add(weaponPicture);
    }

     void UpdatePosition() {
        if (itemPointer != nullptr) {
            auto mousePos = eventHandler::getInstance().getMousePosition();
            weaponPicture->setPosition(static_cast<float>(mousePos.x) + 10.f, static_cast<float>(mousePos.y) + 10.f);
        }
    }

    void Clear() {
        weaponPicture->setSize("0%", "0%");
        itemPointer = nullptr;
    }

    void holdItem(const std::shared_ptr<itemBase>& item) {
        if (item) {
            weaponPicture->getRenderer()->setTexture(tgui::Texture(item->getTexturePath()));
            weaponPicture->setSize("5%", "10%");
            itemPointer = item;
        }
    }

    void Destroy() {
        weaponPicture = nullptr;
        itemPointer = nullptr;
    }

};

#endif //NOTSIMPLEGAME_MOUSECONTAINER_H