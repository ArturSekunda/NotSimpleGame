//
// Created by Artur on 1.10.2025.
//

#ifndef NOTSIMPLEGAME_MAINGAMEHUD_H
#define NOTSIMPLEGAME_MAINGAMEHUD_H

#include <TGUI/Widgets/Panel.hpp>

class mainGameHUD {
     // Panels
     tgui::Panel::Ptr SidePanel = tgui::Panel::create();
     tgui::Panel::Ptr TopPanel = tgui::Panel::create();
public:

    static mainGameHUD& getInstance() {
        static mainGameHUD instance;
        return instance;
    }

    mainGameHUD() = default;
    ~mainGameHUD() = default;

    void initializePanels(tgui::Gui& gui) {
        // Side Panel
        SidePanel->setSize("20%", "100%");
        SidePanel->setPosition("0%", "0%");
        SidePanel->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
        gui.add(SidePanel);

        // Top Panel
        TopPanel->setSize("100%", "10%");
        TopPanel->setPosition("0%", "0%");
        TopPanel->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
        gui.add(TopPanel);
    }
};


#endif //NOTSIMPLEGAME_MAINGAMEHUD_H