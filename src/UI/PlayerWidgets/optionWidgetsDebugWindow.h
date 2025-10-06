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
    void listBoxHandler(tgui::VerticalLayout &PlayerInfo_Normal,
                        tgui::VerticalLayout &PlayerInfo_SkillStats,
                        tgui::VerticalLayout &PlayerInfo_SkillStats_2,
                        tgui::Grid &GridPlayerStatChange_Normal,
                        tgui::Grid &GridPlayerStatChange_SkillStats,
                        debugHandler &debugHandlerInstance);
    tgui::ListBox::Ptr& getListBox() { return ListBox; }

    void CleanUp();

};


#endif //NOTSIMPLEGAME_OPTIONWIDGETSDEBUGWINDOW_H