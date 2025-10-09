

#ifndef NOTSIMPLEGAME_DEBUGWINDOWMANAGER_H
#define NOTSIMPLEGAME_DEBUGWINDOWMANAGER_H
#include "UI/DebugWidgets/panelInsideDebugWindow.h"
#include "UI/DebugWidgets/optionWidgetsDebugWindow.h"
#include <memory>
#include "handlers/debugHandler.h"
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "TGUI/Widgets/ChildWindow.hpp"
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/EditBox.hpp"


class player;
class panelInsideDebugWindow;
class optionWidgetsDebugWindow;
class debugHandler;

class debugWindow {

    std::unique_ptr<debugHandler> debugHandlerInstance;

    std::unique_ptr<panelInsideDebugWindow> debugPanel;
    std::unique_ptr<optionWidgetsDebugWindow> optionList;

    float WindowWidth = 0.f;
    float WindowHeight = 0.f;

    float PreviousWindowWidth = 0.f;
    float PreviousWindowHeight = 0.f;

    tgui::ChildWindow::Ptr DebugWindow = nullptr;

    bool pendingDestruction = false;

    std::map<std::string, int> SkillStats;


public:
    tgui::ChildWindow::Ptr getDebugWindow() { return DebugWindow; }
    const debugHandler& getDebugHandlerInstance()  const { return *debugHandlerInstance; }

    // Constructor and Destructor
    debugWindow() = default;
    ~debugWindow() = default;

    bool isPendingDestruction() const { return pendingDestruction; }

    // Clean up resources
    void CleanUp();

    // Initialize the debug window
    void initializeDebugWindow(tgui::Gui &gui, player& player);

    void update();

    void WindowSizeChanged();

    bool changeSize() const;

    void updateLayoutsAndSizes(std::string PlayerName, bool IsAlive, float Health, float Defense, float Speed, float Mana, int Level, float EXP, float EXP_MAX);

};


#endif //NOTSIMPLEGAME_DEBUGWINDOWMANAGER_H