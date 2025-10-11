

#ifndef NOTSIMPLEGAME_MAINGAMEHUD_H
#define NOTSIMPLEGAME_MAINGAMEHUD_H
#include "MainGameHUDWidgets/panelsWithLayouts.h"
#include "MainGameHUDWidgets/playerNameAndLevel.h"
#include "MainGameHUDWidgets/playerProgressBars.h"
#include "MainGameHUDWidgets/playerStats.h"
#include <memory>
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/Label.hpp"


class playerStats;
class playerNameAndLevel;
class panelsWithLayouts;
class playerProgressBars;
class UIManager;
class debugWindow;
class player;

class mainGameHUD {

    std::unique_ptr<playerProgressBars> ProgressBars = nullptr;
    std::unique_ptr<panelsWithLayouts> PanelsLayouts = nullptr;
    std::unique_ptr<playerNameAndLevel> PlayerNameLevel = nullptr;
    std::unique_ptr<playerStats> PlayerStats = nullptr;

     // Button (Debug only)
     tgui::Button::Ptr DebugButtonForWindow = nullptr;
public:

    mainGameHUD() = default;
    ~mainGameHUD() = default;

    void CleanUp();

    void createHUD(tgui::Gui& gui);

    void initializeDebugButtons(tgui::Gui& gui, UIManager* uiManager, player& player);

    void UpdateUI(const player& p);

    void UpdateTextSizes(float width, float height);

};


#endif //NOTSIMPLEGAME_MAINGAMEHUD_H