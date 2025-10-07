//
// Created by Artur on 5.10.2025.
//

#include "panelInsideDebugWindow.h"

#include "TGUI/Widgets/ChildWindow.hpp"

void panelInsideDebugWindow::initinitializePanel(tgui::ChildWindow &DebugWindow) {
    InsidePanel = tgui::Panel::create();
    if (!InsidePanel) {
        throw std::runtime_error("Failed to create inside panel");
    }
    InsidePanel->setSize("98%","98%");
    InsidePanel->setPosition("1%","1%");
    InsidePanel->getRenderer()->setBackgroundColor(tgui::Color(0, 0, 0, 180));

    initializeLayoutListBox();
    initializePlayerInfo_Normal();
    initializePlayerInfo_SkillStats();
    initializePlayerInfo_SkillStats_2();
    initializeCollisionButton();

    DebugWindow.add(InsidePanel);

}

void panelInsideDebugWindow::initializeLayoutListBox() {
    VerticalLayoutListBox = tgui::VerticalLayout::create();
    if (!VerticalLayoutListBox) {
        throw std::runtime_error("Failed to create vertical layout for list box");
    }
    VerticalLayoutListBox->setSize("30%","98%");
    VerticalLayoutListBox->setPosition("1%","1%");
    VerticalLayoutListBox->getRenderer()->setPadding(5);
    InsidePanel->add(VerticalLayoutListBox);
}

void panelInsideDebugWindow::initializePlayerInfo_Normal() {
    VerticalLayoutPlayerInfo_Normal = tgui::VerticalLayout::create();
    if (!VerticalLayoutPlayerInfo_Normal) {
        throw std::runtime_error("Failed to create vertical layout for player info normal");
    }
    VerticalLayoutPlayerInfo_Normal->setSize("68%","98%");
    VerticalLayoutPlayerInfo_Normal->setPosition("31%","1%");
    VerticalLayoutPlayerInfo_Normal->getRenderer()->setPadding(5);
    VerticalLayoutPlayerInfo_Normal->setVisible(false);
    InsidePanel->add(VerticalLayoutPlayerInfo_Normal);
}

void panelInsideDebugWindow::initializePlayerInfo_SkillStats() {
    VerticalLayoutPlayerInfo_SkillStats = tgui::VerticalLayout::create();
    if (!VerticalLayoutPlayerInfo_SkillStats) {
        throw std::runtime_error("Failed to create vertical layout for player info skillstats");
    }
    VerticalLayoutPlayerInfo_SkillStats->setSize("34%","98%");
    VerticalLayoutPlayerInfo_SkillStats->setPosition("31%","1%");
    VerticalLayoutPlayerInfo_SkillStats->getRenderer()->setPadding(5);
    VerticalLayoutPlayerInfo_Normal->setVisible(false);
    InsidePanel->add(VerticalLayoutPlayerInfo_SkillStats);
}

void panelInsideDebugWindow::initializePlayerInfo_SkillStats_2() {
    VerticalLayoutPlayerInfo_SkillStats_2 = tgui::VerticalLayout::create();
    if (!VerticalLayoutPlayerInfo_SkillStats_2) {
        throw std::runtime_error("Failed to create vertical layout for player info skillstats 2");
    }
    VerticalLayoutPlayerInfo_SkillStats_2->setSize("34%","98%");
    VerticalLayoutPlayerInfo_SkillStats_2->setPosition("65%","1%");
    VerticalLayoutPlayerInfo_SkillStats_2->getRenderer()->setPadding(5);
    VerticalLayoutPlayerInfo_Normal->setVisible(false);
    InsidePanel->add(VerticalLayoutPlayerInfo_SkillStats_2);
}

void panelInsideDebugWindow::initializeCollisionButton() {
    VerticalLayoutCollisionButton = tgui::VerticalLayout::create();
    if (!VerticalLayoutCollisionButton) {
        throw std::runtime_error("Failed to create vertical layout for collision button");
    }
    VerticalLayoutCollisionButton->setSize("68%","98%");
    VerticalLayoutCollisionButton->setPosition("31%","1%");
    VerticalLayoutCollisionButton->getRenderer()->setPadding(5);
    VerticalLayoutCollisionButton->setVisible(true);
    InsidePanel->add(VerticalLayoutCollisionButton);
}
