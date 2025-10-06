

#ifndef NOTSIMPLEGAME_DEBUGWINDOWMANAGER_H
#define NOTSIMPLEGAME_DEBUGWINDOWMANAGER_H
#include "UI/PlayerWidgets/panelInsideDebugWindow.h"
#include "UI/PlayerWidgets/optionWidgetsDebugWindow.h"
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "TGUI/Widgets/ChildWindow.hpp"
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/EditBox.hpp"


class player;
class panelInsideDebugWindow;
class optionWidgetsDebugWindow;
class debugHandler;

class debugWindow {

    std::unique_ptr<panelInsideDebugWindow> debugPanel;
    std::unique_ptr<optionWidgetsDebugWindow> optionList;


    player* currentPlayer = nullptr;

    float WindowWidth = 0.f;
    float WindowHeight = 0.f;

    tgui::ChildWindow::Ptr DebugWindow = nullptr;


public:
    tgui::Widget::Ptr getDebugWindow() { return DebugWindow; }

    // Singleton Pattern
    static debugWindow& getInstance() {
        static debugWindow instance;
        return instance;
    }

    // Constructor and Destructor
    debugWindow() = default;
    ~debugWindow() = default;

    // Clean up resources
    void CleanUp();

    // Initialize the debug window
    void initializeDebugWindow(tgui::Gui &gui);

    void earnMainWindowSize(float width, float height) {
        WindowWidth = width;
        WindowHeight = height;
    }

};


#endif //NOTSIMPLEGAME_DEBUGWINDOWMANAGER_H