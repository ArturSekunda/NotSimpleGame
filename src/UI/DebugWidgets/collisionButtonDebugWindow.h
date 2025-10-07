
#ifndef NOTSIMPLEGAME_COLLISIONBUTTONDEBUGWINDOW_H
#define NOTSIMPLEGAME_COLLISIONBUTTONDEBUGWINDOW_H
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"


class collisionButtonDebugWindow {
    tgui::Button::Ptr CollisionButton = nullptr;
public:
    void initializeCollisionButton(tgui::VerticalLayout::Ptr Layout);

    bool returnCollisionStat = false;

    tgui::Button::Ptr& getCollisionButton() { return CollisionButton; }
    void CleanUp() {
        CollisionButton = nullptr;
    }
};


#endif //NOTSIMPLEGAME_COLLISIONBUTTONDEBUGWINDOW_H