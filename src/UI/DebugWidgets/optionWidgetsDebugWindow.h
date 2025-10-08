//
// Created by Artur on 5.10.2025.
//

#ifndef NOTSIMPLEGAME_OPTIONWIDGETSDEBUGWINDOW_H
#define NOTSIMPLEGAME_OPTIONWIDGETSDEBUGWINDOW_H
#include "TGUI/Widgets/ListBox.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"
#include "TGUI/Widgets/Grid.hpp"
#include "collisionButtonDebugWindow.h"
#include "playerChangeStatsDebugWindow.h"
#include "playerInfoLabelsDebugWindow.h"

class collisionButtonDebugWindow;
class debugHandler;

class optionWidgetsDebugWindow {
    tgui::ListBox::Ptr ListBox = nullptr;
    std::vector<tgui::String> ListBoxNames;

    std::unique_ptr<collisionButtonDebugWindow> CollisionButton;
    std::unique_ptr<playerInfoLabelsDebugWindow> PlayerInfoLabels;
    std::unique_ptr<playerChangeStatsDebugWindow> PlayerStatChange_SkillStats;
public:
    void initializeListBox(tgui::VerticalLayout &Layout);
    void listBoxHandler(tgui::VerticalLayout::Ptr Collision,
                        tgui::VerticalLayout::Ptr PlayerInfo_Normal,
                        tgui::VerticalLayout::Ptr PlayerInfo_SkillStats,
                        tgui::VerticalLayout::Ptr PlayerInfo_SkillStats_2,
                        tgui::Grid::Ptr GridPlayerStatChange_Normal,
                        tgui::Grid::Ptr GridPlayerStatChange_SkillStats);
    void widgetsHandler(debugHandler &debugHandlerInstance);
    tgui::ListBox::Ptr& getListBox() { return ListBox; }

    playerInfoLabelsDebugWindow* getPlayerInfoLabelsDebugWindow() {
        return PlayerInfoLabels.get();
    }
    playerChangeStatsDebugWindow* getPlayerChangeStatsDebugWindow() {
        return PlayerStatChange_SkillStats.get();
    }

    void CleanUp();

};


#endif //NOTSIMPLEGAME_OPTIONWIDGETSDEBUGWINDOW_H