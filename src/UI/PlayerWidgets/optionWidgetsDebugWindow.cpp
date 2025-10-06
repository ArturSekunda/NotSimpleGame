//
// Created by Artur on 5.10.2025.
//

#include "optionWidgetsDebugWindow.h"

#include "handlers/debugHandler.h"
#include "TGUI/Widgets/Label.hpp"

void optionWidgetsDebugWindow::initializeListBox(tgui::VerticalLayout &Layout) {
    ListBox = tgui::ListBox::create();
    ListBoxNames = {"Collision","Player Info","Player Skill Stats Info","Player Stat Change","Player Skill Stat Change"};
    if (!ListBox) {
        throw std::runtime_error("Failed to create list box");
    }

    ListBox->setSize("100%","100%");
    ListBox->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
    ListBox->getRenderer()->setTextColor(tgui::Color::White);
    ListBox->getRenderer()->setBorderColor(tgui::Color(0, 0, 0, 200));
    ListBox->getRenderer()->setBorders(2);
    ListBox->addMultipleItems(ListBoxNames);
    ListBox->setSelectedItem("Player Info");
    Layout.add(ListBox);

}

void optionWidgetsDebugWindow::listBoxHandler(tgui::VerticalLayout &PlayerInfo_Normal,tgui::VerticalLayout &PlayerInfo_SkillStats, tgui::VerticalLayout &PlayerInfo_SkillStats_2,
    tgui::Grid &GridPlayerStatChange_Normal, tgui::Grid &GridPlayerStatChange_SkillStats, debugHandler &debugHandlerInstance) {
    ListBox->onItemSelect([&debugHandlerInstance, &PlayerInfo_Normal,&PlayerInfo_SkillStats,&PlayerInfo_SkillStats_2,&GridPlayerStatChange_Normal,&GridPlayerStatChange_SkillStats](const tgui::String& item) {
        if (item == "Player Info") {
            PlayerInfo_Normal.setVisible(true);
            PlayerInfo_SkillStats.setVisible(false);
            PlayerInfo_SkillStats_2.setVisible(false);
            GridPlayerStatChange_Normal.setVisible(false);
            GridPlayerStatChange_SkillStats.setVisible(false);
        } else if (item == "Player Skill Stats Info") {
            std::printf("Player Skill Stats Info\n");
            PlayerInfo_Normal.setVisible(false);
            PlayerInfo_SkillStats.setVisible(true);
            PlayerInfo_SkillStats_2.setVisible(true);
            GridPlayerStatChange_Normal.setVisible(false);
            GridPlayerStatChange_SkillStats.setVisible(false);
        } else if (item == "Player Stat Change") {
            std::printf("Player Stat Change\n");
            PlayerInfo_Normal.setVisible(false);
            PlayerInfo_SkillStats.setVisible(false);
            PlayerInfo_SkillStats_2.setVisible(false);
            GridPlayerStatChange_Normal.setVisible(true);
            GridPlayerStatChange_SkillStats.setVisible(false);
        } else if (item == "Player Skill Stat Change") {
            std::printf("Player Skill Stat Change\n");
            PlayerInfo_Normal.setVisible(false);
            PlayerInfo_SkillStats.setVisible(false);
            PlayerInfo_SkillStats_2.setVisible(false);
            GridPlayerStatChange_Normal.setVisible(false);
            GridPlayerStatChange_SkillStats.setVisible(true);
        }
    });

}

void optionWidgetsDebugWindow::CleanUp() {
    ListBox = nullptr;
}

