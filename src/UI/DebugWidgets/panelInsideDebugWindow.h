

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
    tgui::VerticalLayout::Ptr VerticalLayoutCollisionButton = nullptr;

    tgui::Grid::Ptr GridPlayerStatChange_Normal = nullptr;
    tgui::Grid::Ptr GridPlayerStatChange_SkillStats = nullptr;
    tgui::Grid::Ptr GridPlayerInfo_SkillStats = nullptr;

public:
    void initinitializePanel(tgui::ChildWindow &DebugWindow);
    void initializeLayoutListBox();
    void initializePlayerInfo_Normal();
    void initializePlayerInfo_SkillStats();
    void initializeCollisionButton();
    void initializePlayerStatChange_Normal();
    void initializePlayerStatChange_SkillStats();

    void CleanUp() {
        InsidePanel = nullptr;
        VerticalLayoutListBox = nullptr;
        VerticalLayoutPlayerInfo_Normal = nullptr;
        GridPlayerInfo_SkillStats = nullptr;
        GridPlayerStatChange_Normal = nullptr;
        GridPlayerStatChange_SkillStats = nullptr;
        VerticalLayoutCollisionButton = nullptr;
        getAllWidgets.clear();
    }

    // Getters
    tgui::Panel::Ptr getInsidePanel() { return InsidePanel; }

    tgui::VerticalLayout::Ptr getVerticalLayoutListBox() { return VerticalLayoutListBox; }

    std::map<std::string, tgui::Widget::Ptr> getAllWidgets;

};


#endif //NOTSIMPLEGAME_PANELINSIDEDEBUGWINDOW_H