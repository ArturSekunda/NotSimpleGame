
#include "collisionButtonDebugWindow.h"

void collisionButtonDebugWindow::initializeCollisionButton(tgui::VerticalLayout::Ptr Layout) {
    CollisionButton = tgui::Button::create("Collision");
    if (!CollisionButton) {
        throw std::runtime_error("Failed to create collision button");
    }
    CollisionButton->setSize("10%","10%");
    CollisionButton->setPosition("70%","1%");
    CollisionButton->getRenderer()->setBackgroundColor(tgui::Color(100, 100, 100, 200));
    CollisionButton->getRenderer()->setTextColor(tgui::Color::White);
    CollisionButton->getRenderer()->setBorderColor(tgui::Color(0, 0, 0, 200));
    CollisionButton->getRenderer()->setBorders(2);

    Layout->add(CollisionButton);
}
