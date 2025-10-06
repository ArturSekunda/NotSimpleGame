//
// Created by Artur on 5.10.2025.
//

#ifndef NOTSIMPLEGAME_OPTIONWIDGETSDEBUGWINDOW_H
#define NOTSIMPLEGAME_OPTIONWIDGETSDEBUGWINDOW_H
#include "TGUI/Widgets/ListBox.hpp"
#include "TGUI/Widgets/VerticalLayout.hpp"
#include "TGUI/Widgets/Grid.hpp"

class debugHandler;

class optionWidgetsDebugWindow {
    tgui::ListBox::Ptr ListBox = nullptr;
    std::vector<tgui::String> ListBoxNames;
public:
    void initializeListBox(tgui::VerticalLayout &Layout);
    void listBoxHandler(tgui::VerticalLayout::Ptr Collision,
                        tgui::VerticalLayout::Ptr PlayerInfo_Normal,
                        tgui::VerticalLayout::Ptr PlayerInfo_SkillStats,
                        tgui::VerticalLayout::Ptr PlayerInfo_SkillStats_2,
                        tgui::Grid::Ptr GridPlayerStatChange_Normal,
                        tgui::Grid::Ptr GridPlayerStatChange_SkillStats);
    tgui::ListBox::Ptr& getListBox() { return ListBox; }

    void CleanUp();

};


#endif //NOTSIMPLEGAME_OPTIONWIDGETSDEBUGWINDOW_H