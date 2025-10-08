//
// Created by Artur on 5.10.2025.
//

#ifndef NOTSIMPLEGAME_PANELINSIDEDEBUGWINDOW_H
#define NOTSIMPLEGAME_PANELINSIDEDEBUGWINDOW_H
#include "TGUI/Widgets/Panel.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/Grid.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"

class panelInsideDebugWindow {
    tgui::Panel::Ptr InsidePanel = nullptr;

    tgui::VerticalLayout::Ptr VerticalLayoutListBox = nullptr;

    tgui::VerticalLayout::Ptr VerticalLayoutPlayerInfo_Normal = nullptr;
    tgui::VerticalLayout::Ptr VerticalLayoutPlayerInfo_SkillStats = nullptr;
    tgui::VerticalLayout::Ptr VerticalLayoutPlayerInfo_SkillStats_2 = nullptr;
    tgui::VerticalLayout::Ptr VerticalLayoutCollisionButton = nullptr;

    tgui::Grid::Ptr GridPlayerStatChange_Normal = nullptr;
    tgui::Grid::Ptr GridPlayerStatChange_SkillStats = nullptr;

public:
    void initinitializePanel(tgui::ChildWindow &DebugWindow);
    void initializeLayoutListBox();
    void initializePlayerInfo_Normal();
    void initializePlayerInfo_SkillStats();
    void initializePlayerInfo_SkillStats_2();
    void initializeCollisionButton();
    void initializePlayerStatChange_Normal();
    void initializePlayerStatChange_SkillStats();

    void CleanUp() {
        InsidePanel = nullptr;
        VerticalLayoutListBox = nullptr;
        VerticalLayoutPlayerInfo_Normal = nullptr;
        VerticalLayoutPlayerInfo_SkillStats = nullptr;
        VerticalLayoutPlayerInfo_SkillStats_2 = nullptr;
        GridPlayerStatChange_Normal = nullptr;
        GridPlayerStatChange_SkillStats = nullptr;
        VerticalLayoutCollisionButton = nullptr;
    }

    // Getters
    tgui::Panel::Ptr getInsidePanel() { return InsidePanel; }
    tgui::VerticalLayout::Ptr getVerticalLayoutListBox() { return VerticalLayoutListBox; }
    tgui::VerticalLayout::Ptr getVerticalLayoutPlayerInfo_Normal() { return VerticalLayoutPlayerInfo_Normal; }
    tgui::VerticalLayout::Ptr getVerticalLayoutPlayerInfo_SkillStats() { return VerticalLayoutPlayerInfo_SkillStats; }
    tgui::VerticalLayout::Ptr getVerticalLayoutPlayerInfo_SkillStats_2() { return VerticalLayoutPlayerInfo_SkillStats_2; }
    tgui::VerticalLayout::Ptr getVerticalLayoutCollisionButton() { return VerticalLayoutCollisionButton; }
    tgui::Grid::Ptr getGridPlayerStatChange_Normal() { return GridPlayerStatChange_Normal; }
    tgui::Grid::Ptr getGridPlayerStatChange_SkillStats() { return GridPlayerStatChange_SkillStats; }

};


#endif //NOTSIMPLEGAME_PANELINSIDEDEBUGWINDOW_H