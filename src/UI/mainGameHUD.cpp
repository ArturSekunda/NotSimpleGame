#include "mainGameHUD.h"

#include "debugWindow.h"
#include "entities/player/player.h"
#include "managers/UIManager.h"

void mainGameHUD::initializePanels(tgui::Gui &gui) {
    // Create Panels
    SidePanel = tgui::Panel::create();
    TopPanel = tgui::Panel::create();

    if (!SidePanel || !TopPanel) {
        throw std::runtime_error("Failed to create panels");
    }

    // Side Panel
    SidePanel->setSize("20%", "100%");
    SidePanel->setPosition("80%", "15%");
    SidePanel->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
    gui.add(SidePanel);

    // Top Panel
    TopPanel->setSize("100%", "15%");
    TopPanel->setPosition("0%", "0%");
    TopPanel->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 50, 200));
    gui.add(TopPanel);
}

void mainGameHUD::initializeBars() {
    // Create Bars
    HealthBar = tgui::ProgressBar::create();
    ManaBar = tgui::ProgressBar::create();
    XPBar = tgui::ProgressBar::create();
    StatsLayout = tgui::VerticalLayout::create();

    if (!HealthBar || !ManaBar || !XPBar) {
        throw std::runtime_error("Failed to create progress bars");
    }

    if (!StatsLayout) {
        throw std::runtime_error("Failed to create stats layout");
    }

    // Health Bar
    HealthBar->setSize("20%", "20%");
    HealthBar->setMinimum(0);
    HealthBar->getRenderer()->setBorderColor(tgui::Color(0, 0, 0, 200));
    HealthBar->getRenderer()->setBorders(2);
    HealthBar->getRenderer()->setFillColor(tgui::Color(255, 50, 50, 200));
    HealthBar->getRenderer()->setBackgroundColor(tgui::Color(255, 50, 50, 255));
    StatsLayout->add(HealthBar);

    // Mana Bar
    ManaBar->setSize("20%", "20%");
    ManaBar->setMinimum(0);
    ManaBar->getRenderer()->setBorderColor(tgui::Color(0, 0, 0, 200));
    ManaBar->getRenderer()->setBorders(2);
    ManaBar->getRenderer()->setFillColor(tgui::Color(50, 50, 255, 200));
    ManaBar->getRenderer()->setBackgroundColor(tgui::Color(50, 50, 255, 255));
    StatsLayout->add(ManaBar);

    // XP Bar
    XPBar->setSize("20%", "20%");
    XPBar->setMinimum(0);
    XPBar->getRenderer()->setBorderColor(tgui::Color(0, 0, 0, 200));
    XPBar->getRenderer()->setBorders(2);
    XPBar->getRenderer()->setFillColor(tgui::Color(0, 160, 16, 200));
    XPBar->getRenderer()->setBackgroundColor(tgui::Color(50, 255, 50, 255));
    StatsLayout->add(XPBar);

    // Stats Layout
    StatsLayout->setSize("40%", "60%");
    StatsLayout->setPosition("0%", "20%");
    StatsLayout->getRenderer()->setSpaceBetweenWidgets(3);
    StatsLayout->getRenderer()->setPadding(5);
    TopPanel->add(StatsLayout);

}

void mainGameHUD::initializeDebugButtons(tgui::Gui &gui, UIManager* uiManager, player& player) {
    // Create Debug Button
    DebugButtonForWindow = tgui::Button::create("Debug");
    if (!DebugButtonForWindow) {
        throw std::runtime_error("Failed to create debug button");
    }

    DebugButtonForWindow->setSize("10%", "10%");
    DebugButtonForWindow->setPosition("5%", "85%");
    DebugButtonForWindow->getRenderer()->setBackgroundColor(tgui::Color(100, 100, 100, 200));
    DebugButtonForWindow->getRenderer()->setTextColor(tgui::Color::White);

    DebugButtonForWindow->onPress([&gui, uiManager, &player]() {
        uiManager->CreateDebugWindow(gui, player);
    });
    gui.add(DebugButtonForWindow);

}

void mainGameHUD::DisplayPlayerNameAndLevel(const player &p) {

    // Create Labels
    PlayerNameLabel = tgui::Label::create();
    XPLabel = tgui::Label::create();
    PlayerNameEXPLayout = tgui::VerticalLayout::create();

    if (!PlayerNameLabel || !XPLabel || !PlayerNameEXPLayout) {
        throw std::runtime_error("Failed to create labels");
    }

    // Player Name Label
    PlayerNameLabel->setText(p.getPlayerName());
    PlayerNameLabel->getRenderer()->setTextColor(tgui::Color::White);
    PlayerNameEXPLayout->add(PlayerNameLabel);

    // XP Label
    XPLabel->getRenderer()->setTextColor(tgui::Color::White);
    PlayerNameEXPLayout->add(XPLabel);

    // Player Name and XP Layout
    PlayerNameEXPLayout->setSize("40%", "90%");
    PlayerNameEXPLayout->setPosition("50%", "10%");
    PlayerNameEXPLayout->getRenderer()->setSpaceBetweenWidgets(3);
    PlayerNameEXPLayout->getRenderer()->setPadding(5);
    TopPanel->add(PlayerNameEXPLayout);
}

void mainGameHUD::UpdateUI(const player &p) {
    // Update XP Label
    XPLabel->setText("Level: " + std::to_string(p.getLevel()));

    // Update Health Bar
    HealthBar->setMaximum(p.getMaxHealth());
    HealthBar->setValue(p.getHealth());
    HealthBar->setText("Health: " + std::to_string(static_cast<int>(p.getHealth())) + " / " + std::to_string(static_cast<int>(p.getMaxHealth())));

    // Update Mana Bar
    ManaBar->setMaximum(p.getMaxMana());
    ManaBar->setValue(p.getMana());
    ManaBar->setText("Mana: " + std::to_string(static_cast<int>(p.getMana())) + " / " + std::to_string(static_cast<int>(p.getMaxMana())));

    // Update XP Bar
    XPBar->setMaximum(p.getEXP_MAX());
    XPBar->setValue(p.getEXP());
    XPBar->setText("XP: " + std::to_string(static_cast<int>(p.getEXP())) + " / " + std::to_string(static_cast<int>(p.getEXP_MAX())));

}

void mainGameHUD::UpdateTextSizes(float width, float height) {

    windowHeight = height;
    windowWidth = width;

    if (PlayerNameLabel) {
        PlayerNameLabel->setTextSize(static_cast<unsigned int>(windowHeight * 0.04f));
    }
    if (XPLabel) {
        XPLabel->setTextSize(static_cast<unsigned int>(windowHeight * 0.03f));
    }
}
