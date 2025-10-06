
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
    optionList->listBoxHandler(debugPanel->getVerticalLayoutCollisionButton(),debugPanel->getVerticalLayoutPlayerInfo_Normal(),debugPanel->getVerticalLayoutPlayerInfo_SkillStats(),debugPanel->getVerticalLayoutPlayerInfo_SkillStats_2(), debugPanel->getGridPlayerStatChange_Normal(),debugPanel->getGridPlayerStatChange_SkillStats());


    gui.add(DebugWindow);
    DebugWindow->onClose([this]() {
        CleanUp();

    });
}
void debugWindow::CleanUp() {
    debugPanel->CleanUp();
    optionList->CleanUp();
    WindowWidth = 0.f;
    WindowHeight = 0.f;
    DebugWindow = nullptr;
}