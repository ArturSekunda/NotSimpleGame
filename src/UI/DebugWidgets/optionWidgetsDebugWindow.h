//
// Created by Artur on 5.10.2025.
//

#ifndef NOTSIMPLEGAME_OPTIONWIDGETSDEBUGWINDOW_H
#define NOTSIMPLEGAME_OPTIONWIDGETSDEBUGWINDOW_H
#include "TGUI/Widgets/ListBox.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"
#include "collisionButtonDebugWindow.h"
#include "playerChangeNormalStatsDebugWindow.h"
#include "playerChangeStatsDebugWindow.h"
#include "playerInfoLabelsDebugWindow.h"

enum class ActivePanel {
    Collision,
    PlayerInfo,
    PlayerSkillStatsInfo,
    PlayerStatChange,
    PlayerSkillStatChange
};

class collisionButtonDebugWindow;
class debugHandler;

class optionWidgetsDebugWindow {
    ActivePanel currentPanel = ActivePanel::Collision;
    tgui::ListBox::Ptr ListBox = nullptr;
    std::vector<tgui::String> ListBoxNames;

    std::unique_ptr<collisionButtonDebugWindow> CollisionButton;
    std::unique_ptr<playerInfoLabelsDebugWindow> PlayerInfoLabels;
    std::unique_ptr<playerChangeStatsDebugWindow> PlayerStatChange_SkillStats;
    std::unique_ptr<playerChangeNormalStatsDebugWindow> PlayerChangeNormalStats;



    std::map<ActivePanel, tgui::Widget::Ptr> PanelWidgets;
    std::map<tgui::String, ActivePanel> ItemToPanel;

public:
    void initializeListBox(tgui::VerticalLayout &Layout);
    void listBoxHandler(std::map<std::string, tgui::Widget::Ptr> AllWidgets);
    void widgetsHandler(debugHandler &debugHandlerInstance);
    tgui::ListBox::Ptr& getListBox() { return ListBox; }

    ActivePanel getCurrentPanel() const { return currentPanel; }

    playerInfoLabelsDebugWindow* getPlayerInfoLabelsDebugWindow() {
        return PlayerInfoLabels.get();
    }
    playerChangeStatsDebugWindow* getPlayerChangeStatsDebugWindow() {
        return PlayerStatChange_SkillStats.get();
    }
    playerChangeNormalStatsDebugWindow* getPlayerChangeNormalStatsDebugWindow() {
        return PlayerChangeNormalStats.get();
    }


    void CleanUp();

};


#endif //NOTSIMPLEGAME_OPTIONWIDGETSDEBUGWINDOW_H