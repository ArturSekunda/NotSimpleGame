#ifndef NOTSIMPLEGAME_PLAYERADDPOINTSTOSTATS_H
#define NOTSIMPLEGAME_PLAYERADDPOINTSTOSTATS_H
#include "TGUI/Widgets/ChildWindow.hpp"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"

class playerAddPointsToStats {

    tgui::ChildWindow::Ptr Stats_Window = nullptr;
    tgui::Button::Ptr Opener_button = nullptr;

public:

    void initializeWindow(tgui::SFML_GRAPHICS::Gui& gui, float windowWidth, float windowHeight);

    void initializeOpenerButton(tgui::Gui& gui);

    void UpdateWindowVisibility(bool isVisible);

    bool getIsWindowOpen() const {
        return Stats_Window->isVisible();
    }

    void setIsWindowOpen(bool isOpen) {
        Stats_Window->setVisible(isOpen);
    }
};


#endif //NOTSIMPLEGAME_PLAYERADDPOINTSTOSTATS_H