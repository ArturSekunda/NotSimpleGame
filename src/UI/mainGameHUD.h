

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
#include "MainGameHUDWidgets/playerEquipmentWidget.h"
#include "MainGameHUDWidgets/playerInventoryWidget.h"
#include "helpers/mouseContainer.h"
#include "MainGameHUDWidgets/waveCounter.h"

class entitiesManager;
class playerEquipmentWidget;
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
    std::unique_ptr<playerEquipmentWidget> EquipmentWidget = nullptr;
    std::unique_ptr<playerInventoryWidget> InventoryWidget = nullptr;
    std::unique_ptr<waveCounter> WaveCounterWidget = nullptr;

     // Button (Debug only)
     tgui::Button::Ptr DebugButtonForWindow = nullptr;
public:

    mainGameHUD() = default;
    ~mainGameHUD() = default;

    MouseContainer Mouse;

    player* HolderPlayer;

    entitiesManager* HolderEntitiesManager;

    waveCounter& getWaveCounterWidget() {
        return *WaveCounterWidget;
    }

    void CleanUp();

    void createHUD(tgui::Gui& gui);

    void initializeDebugButtons(tgui::Gui& gui, UIManager* uiManager, player& player);

    void UpdateUI(player& p);

    void UpdateTextSizes(float width, float height);

    void SetHolderPlayer(player& p) {
        HolderPlayer = &p;
    }

    void SetHolderEntitiesManager(entitiesManager& em) {
        HolderEntitiesManager = &em;
    }

};


#endif //NOTSIMPLEGAME_MAINGAMEHUD_H