//
// Created by Artur on 1.10.2025.
//

#ifndef NOTSIMPLEGAME_MAINGAMEHUD_H
#define NOTSIMPLEGAME_MAINGAMEHUD_H
#include <TGUI/Widgets/Panel.hpp>

#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/ProgressBar.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"


class debugWindow;
class player;

class mainGameHUD {
     // Panels
     tgui::Panel::Ptr SidePanel = nullptr;
     tgui::Panel::Ptr TopPanel = nullptr;
     // Bars
     tgui::ProgressBar::Ptr HealthBar = nullptr;
     tgui::ProgressBar::Ptr ManaBar = nullptr;
     tgui::ProgressBar::Ptr XPBar = nullptr;
     // Layouts
     tgui::VerticalLayout::Ptr PlayerNameEXPLayout = nullptr;
     tgui::VerticalLayout::Ptr StatsLayout = nullptr;
     // Labels
     tgui::Label::Ptr PlayerNameLabel = nullptr;
     tgui::Label::Ptr XPLabel = nullptr;
     // Button (Debug only)
     tgui::Button::Ptr DebugButtonForWindow = nullptr;
private:
    float windowWidth = 0.f;
    float windowHeight = 0.f;
public:

    mainGameHUD() = default;
    ~mainGameHUD() = default;

    void CleanUp() {
        SidePanel = nullptr;
        TopPanel = nullptr;
        HealthBar = nullptr;
        ManaBar = nullptr;
        XPBar = nullptr;
        StatsLayout = nullptr;
        PlayerNameEXPLayout = nullptr;
        PlayerNameLabel = nullptr;
        XPLabel = nullptr;
        DebugButtonForWindow = nullptr;
    }

    void initializePanels(tgui::Gui& gui);
    void initializeBars();
    void initializeDebugButtons(tgui::Gui& gui, debugWindow& debugWindow);
    void DisplayPlayerNameAndLevel(const player& p);

    void UpdateUI(const player& p);

    void UpdateTextSizes(float width, float height);

};


#endif //NOTSIMPLEGAME_MAINGAMEHUD_H