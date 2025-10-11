

#include "panelsWithLayouts.h"

void panelsWithLayouts::CombineAll(tgui::Gui &gui) {

    initializePanels(gui);

    initializePlayerNameEXPLayout();

    initializeStatsLayout();

    initializeStatsGridPanel();

    Layouts = {
        {"PlayerNameEXPLayout", PlayerNameEXPLayout},
        {"StatsLayout", StatsLayout},
        {"GridStats", StatsGrid}
    };

}
void panelsWithLayouts::initializePanels(tgui::Gui &gui) {
    Side_PlayerPanel = tgui::Panel::create();
    Top_InfoPanel = tgui::Panel::create();
    MainPanel  = tgui::Panel::create();

    if (!Side_PlayerPanel || !Top_InfoPanel || !MainPanel) {
        throw std::runtime_error("Failed to create panels");
    }

    // Main Panel
    MainPanel->setSize("100%", "100%");
    MainPanel->setPosition("0%", "0%");
    MainPanel->getRenderer()->setBackgroundColor(tgui::Color(0, 0, 0, 0));
    gui.add(MainPanel);

    // Side Player Panel
    Side_PlayerPanel->setSize("20%", "85%");
    Side_PlayerPanel->setPosition("80%", "15%");
    Side_PlayerPanel->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
    MainPanel->add(Side_PlayerPanel);

    // Top Info Panel
    Top_InfoPanel->setSize("100%", "15%");
    Top_InfoPanel->setPosition("0%", "0%");
    Top_InfoPanel->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
    MainPanel->add(Top_InfoPanel);
}

void panelsWithLayouts::initializePlayerNameEXPLayout() {
    PlayerNameEXPLayout = tgui::VerticalLayout::create();
    if (!PlayerNameEXPLayout) {
        throw std::runtime_error("Failed to create player name and EXP layout");
    }

    // Player Name and XP Layout
    PlayerNameEXPLayout->setSize("20%", "90%");
    PlayerNameEXPLayout->setPosition("80%", "0%");
    PlayerNameEXPLayout->getRenderer()->setSpaceBetweenWidgets(5);
    PlayerNameEXPLayout->getRenderer()->setPadding(5);
    Top_InfoPanel->add(PlayerNameEXPLayout);
}

void panelsWithLayouts::initializeStatsLayout() {
    StatsLayout = tgui::VerticalLayout::create();
    if (!StatsLayout) {
        throw std::runtime_error("Failed to create stats layout");
    }

    // Stats Layout
    StatsLayout->setSize("40%", "90%");
    StatsLayout->setPosition("0%", "0%");
    StatsLayout->getRenderer()->setSpaceBetweenWidgets(20);
    StatsLayout->getRenderer()->setPadding(5);
    Top_InfoPanel->add(StatsLayout);
}

void panelsWithLayouts::initializeStatsGridPanel() {
    StatsGrid = tgui::Grid::create();
    if (!StatsGrid) {
        throw std::runtime_error("Failed to create stats grid panel");
    }
    // Stats Grid Panel
    StatsGrid->setSize("30%", "90%");
    StatsGrid->setPosition("45%", "0%");
    Top_InfoPanel->add(StatsGrid);
}