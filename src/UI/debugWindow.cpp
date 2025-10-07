
#include "debugWindow.h"

#include "DebugWidgets/collisionButtonDebugWindow.h"
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
    optionList->listBoxHandler(debugPanel->getVerticalLayoutCollisionButton(),debugPanel->getVerticalLayoutPlayerInfo_Normal(),debugPanel->getVerticalLayoutPlayerInfo_SkillStats(),debugPanel->getVerticalLayoutPlayerInfo_SkillStats_2(), debugPanel->getGridPlayerStatChange_Normal(),debugPanel->getGridPlayerStatChange_SkillStats());
    optionList->widgetsHandler(*debugHandlerInstance);


    gui.add(DebugWindow);
    DebugWindow->onClose([this]() {
        pendingDestruction = true;

        if (DebugWindow) {
            DebugWindow->setVisible(false);
        }

    });
}

void debugWindow::update(player &p) {
    if (!debugHandlerInstance) {
        return;
    }

    tgui::Vector2f debugWindowSize = DebugWindow->getSize();
    WindowWidth = debugWindowSize.x;
    WindowHeight = debugWindowSize.y;



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
    auto Strength = skillStats.strength;
    auto Dexterity = skillStats.dexterity;
    auto Intelligence = skillStats.intelligence;
    auto Endurance = skillStats.endurance;
    auto Luck = skillStats.luck;
    auto Charisma = skillStats.charisma;
    auto Vitality = skillStats.vitality;
    auto Points = skillStats.points;

    if (!optionList->getPlayerInfoLabelsDebugWindow()) {
        return;
    }
    optionList->getPlayerInfoLabelsDebugWindow()->updatePlayerInfo_Normal(
        PlayerName,
        IsAlive,
        static_cast<int>(Health),
        static_cast<int>(Defense),
        static_cast<int>(Speed),
        static_cast<int>(Mana),
        Level,
        EXP,
        EXP_MAX
    );

    optionList->getPlayerInfoLabelsDebugWindow()->updatePlayerInfo_SkillStats(
        Strength,
        Dexterity,
        Intelligence,
        Endurance
    );

    optionList->getPlayerInfoLabelsDebugWindow()->updatePlayerInfo_SkillStats_2(
        Luck,
        Charisma,
        Vitality,
        Points
    );

    optionList->getPlayerInfoLabelsDebugWindow()->UpdateTextSizes(WindowWidth, WindowHeight);
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

    WindowWidth = 0.f;
    WindowHeight = 0.f;
}
