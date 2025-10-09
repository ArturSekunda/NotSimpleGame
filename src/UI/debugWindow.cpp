
#include "debugWindow.h"

#include "entities/player/player.h"
#include "DebugWidgets/optionWidgetsDebugWindow.h"

void debugWindow::initializeDebugWindow(tgui::Gui &gui, player& player) {

    DebugWindow = tgui::ChildWindow::create("Debug Menu");
    debugHandlerInstance = std::make_unique<debugHandler>(player);
    debugPanel = std::make_unique<panelInsideDebugWindow>();
    optionList = std::make_unique<optionWidgetsDebugWindow>();

    if (!DebugWindow || !debugPanel) {
        throw std::runtime_error("Failed to create debug window");
    }

    DebugWindow->setSize("30%", "40%");
    DebugWindow->setPosition("35%", "30%");
    DebugWindow->setResizable(true);
    DebugWindow->getRenderer()->setBackgroundColor(tgui::Color(70, 70, 70, 220));
    DebugWindow->getRenderer()->setBorderColor(tgui::Color(0, 0, 0, 200));
    DebugWindow->getRenderer()->setBorders(2);

    // Initialize other parts of the debug window
    debugPanel->initinitializePanel(*DebugWindow);
    optionList->initializeListBox(*debugPanel->getVerticalLayoutListBox());
    optionList->listBoxHandler(debugPanel->getAllWidgets);
    optionList->widgetsHandler(*debugHandlerInstance);


    gui.add(DebugWindow);
    DebugWindow->onClose([this]() {
        pendingDestruction = true;

        if (DebugWindow) {
            DebugWindow->setVisible(false);
        }

    });
}

void debugWindow::update() {

    WindowSizeChanged();

    std::string PlayerName = debugHandlerInstance->getPlayerName();
    auto IsAlive = debugHandlerInstance->getIsPlayerAlive();
    auto Health = debugHandlerInstance->getPlayerHealth();
    auto Defense = debugHandlerInstance->getPlayerDefense();
    auto Speed = debugHandlerInstance->getPlayerSpeed();
    auto Mana = debugHandlerInstance->getPlayerMana();
    auto Level = debugHandlerInstance->getPlayerLevel();
    auto EXP = debugHandlerInstance->getPlayerEXP();
    auto EXP_MAX = debugHandlerInstance->getPlayerEXPMax();


    baseStats skillStats = debugHandlerInstance->getPlayerBaseStats();
    SkillStats["Strength"] = skillStats.strength;
    SkillStats["Dexterity"] = skillStats.dexterity;
    SkillStats["Intelligence"] = skillStats.intelligence;
    SkillStats["Endurance"] = skillStats.endurance;
    SkillStats["Luck"] = skillStats.luck;
    SkillStats["Charisma"] = skillStats.charisma;
    SkillStats["Vitality"] = skillStats.vitality;
    SkillStats["Points"] = skillStats.points;

    updateLayoutsAndSizes(PlayerName, IsAlive, Health, Defense, Speed, Mana, Level, EXP, EXP_MAX);

    if (changeSize()) {
        PreviousWindowWidth = WindowWidth;
        PreviousWindowHeight = WindowHeight;
    }
}

void debugWindow::WindowSizeChanged() {
    tgui::Vector2f debugWindowSize = DebugWindow->getSize();
    WindowWidth = debugWindowSize.x;
    WindowHeight = debugWindowSize.y;
}

bool debugWindow::changeSize() const {

    const float SIZE_THRESHOLD = 2.0f;
    float widthDiff = std::abs(WindowWidth - PreviousWindowWidth);
    float heightDiff = std::abs(WindowHeight - PreviousWindowHeight);
    return widthDiff >= SIZE_THRESHOLD || heightDiff >= SIZE_THRESHOLD;
}

void debugWindow::updateLayoutsAndSizes(std::string PlayerName, bool IsAlive, float Health, float Defense, float Speed, float Mana, int Level, float EXP, float EXP_MAX) {
    switch (optionList->getCurrentPanel()) {
        case ActivePanel::Collision:

            break;
        case ActivePanel::PlayerInfo: {
            optionList->getPlayerInfoLabelsDebugWindow()->updatePlayerInfo_Normal(
                PlayerName, IsAlive, static_cast<int>(Health),
                static_cast<int>(Defense), static_cast<int>(Speed),
                static_cast<int>(Mana), Level, EXP, EXP_MAX
            );

            if (changeSize()) {
                optionList->getPlayerInfoLabelsDebugWindow()->UpdateTextSizes_Normal(WindowWidth, WindowHeight);
            }

            break;
        }
        case ActivePanel::PlayerSkillStatsInfo: {
            optionList->getPlayerInfoLabelsDebugWindow()->updatePlayerInfo_SkillStats(
                SkillStats.at("Strength"), SkillStats.at("Dexterity"), SkillStats.at("Intelligence"), SkillStats.at("Endurance"), SkillStats.at("Luck"), SkillStats.at("Charisma"), SkillStats.at("Vitality"), SkillStats.at("Points")
            );

            if (changeSize()) {
                optionList->getPlayerInfoLabelsDebugWindow()->UpdateTextSizes_SkillStats(WindowWidth, WindowHeight);
            }

            break;
        }
        case ActivePanel::PlayerStatChange:

            break;
        case ActivePanel::PlayerSkillStatChange: {
            optionList->getPlayerChangeStatsDebugWindow()->UpdateTextInfo(
                SkillStats.at("Strength"), SkillStats.at("Dexterity"), SkillStats.at("Intelligence"), SkillStats.at("Endurance"),
                SkillStats.at("Luck"), SkillStats.at("Charisma"), SkillStats.at("Vitality"), SkillStats.at("Points")
            );

            if (changeSize()) {
                optionList->getPlayerChangeStatsDebugWindow()->UpdateSizes(WindowWidth, WindowHeight);
            }
            break;
        }
        default:
            std::fprintf(stderr, "Unknown ActivePanel state\n");
            break;
    }
}

void debugWindow::CleanUp() {
    if (DebugWindow) {
        DebugWindow->onClose.disconnectAll();

        DebugWindow = nullptr;
    }

    if (optionList) {
        optionList->CleanUp();
        optionList.reset();
    }

    if (debugPanel) {
        debugPanel->CleanUp();
        debugPanel.reset();
    }

    debugHandlerInstance.reset();

    SkillStats.clear();

    WindowWidth = 0.f;
    WindowHeight = 0.f;
}
