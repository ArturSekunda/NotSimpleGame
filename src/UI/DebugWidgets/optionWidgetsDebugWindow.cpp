
#include "optionWidgetsDebugWindow.h"

#include "handlers/debugHandler.h"
#include "TGUI/Widgets/Label.hpp"

void optionWidgetsDebugWindow::initializeListBox(tgui::VerticalLayout &Layout) {
    ListBox = tgui::ListBox::create();
    CollisionButton = std::make_unique<collisionButtonDebugWindow>();
    PlayerInfoLabels = std::make_unique<playerInfoLabelsDebugWindow>();
    PlayerStatChange_SkillStats = std::make_unique<playerChangeStatsDebugWindow>();
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
    ListBox->setSelectedItem("Collision");
    Layout.add(ListBox);

}

void optionWidgetsDebugWindow::listBoxHandler(std::map<std::string, tgui::Widget::Ptr> AllWidgets) {
    auto Collision = AllWidgets.at("CollisionButton")->cast<tgui::VerticalLayout>();
    auto PlayerInfo_Normal = AllWidgets.at("PlayerInfo_Normal")->cast<tgui::VerticalLayout>();
    auto PlayerInfo_SkillStats = AllWidgets.at("PlayerInfo_SkillStats")->cast<tgui::Grid>();
    auto GridPlayerStatChange_Normal = AllWidgets.at("PlayerStatChange_Normal")->cast<tgui::Grid>();
    auto GridPlayerStatChange_SkillStats = AllWidgets.at("PlayerStatChange_SkillStats")->cast<tgui::Grid>();

    ItemToPanel["Collision"] = ActivePanel::Collision;
    ItemToPanel["Player Info"] = ActivePanel::PlayerInfo;
    ItemToPanel["Player Skill Stats Info"] = ActivePanel::PlayerSkillStatsInfo;
    ItemToPanel["Player Stat Change"] = ActivePanel::PlayerStatChange;
    ItemToPanel["Player Skill Stat Change"] = ActivePanel::PlayerSkillStatChange;

    PanelWidgets[ActivePanel::Collision] = Collision;
    PanelWidgets[ActivePanel::PlayerInfo] = PlayerInfo_Normal;
    PanelWidgets[ActivePanel::PlayerSkillStatsInfo] = PlayerInfo_SkillStats;
    PanelWidgets[ActivePanel::PlayerStatChange] = GridPlayerStatChange_Normal;
    PanelWidgets[ActivePanel::PlayerSkillStatChange] = GridPlayerStatChange_SkillStats;

    CollisionButton->initializeCollisionButton(Collision);
    PlayerInfoLabels->initializePlayerInfo_Normal(PlayerInfo_Normal);
    PlayerInfoLabels->initializePlayerInfo_SkillStats(PlayerInfo_SkillStats);
    PlayerInfoLabels->combineAllVectors();
    PlayerStatChange_SkillStats->initializePlayerChangeStats(GridPlayerStatChange_SkillStats);



    ListBox->onItemSelect([this](const tgui::String& item) {

    auto it = ItemToPanel.find(item.toStdString());
    if (it == ItemToPanel.end()) return;

    ActivePanel selectedPanel = it->second;
    currentPanel = selectedPanel;

    for (auto& [panel, widget] : PanelWidgets) {
        widget->setVisible(false);
    }

    PanelWidgets[selectedPanel]->setVisible(true);
    });

}

void optionWidgetsDebugWindow::widgetsHandler(debugHandler &debugHandlerInstance) {

    CollisionButton->getCollisionButton()->onClick([&debugHandlerInstance] {
        debugHandlerInstance.ShowCollisionBoxes();
    });
     PlayerStatChange_SkillStats->HandleButtonClicks(debugHandlerInstance.getPlayerBaseStats());
}

void optionWidgetsDebugWindow::CleanUp() {
    ListBox = nullptr;

    CollisionButton->CleanUp();
    PlayerInfoLabels->CleanUp();
    PlayerStatChange_SkillStats->CleanUp();
}



