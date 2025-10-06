#pragma once
#include <memory>
#include "UI/debugWindow.h"
#include "UI/mainGameHUD.h"
#include <TGUI/Backend/SFML-Graphics.hpp>


class mainGameHUD;
class gameMenu;
class player;
class debugWindow;

#ifndef NOTSIMPLEGAME_UIMANAGER_H
#define NOTSIMPLEGAME_UIMANAGER_H


class UIManager {
private:
    std::unique_ptr<mainGameHUD> MainGameHUD = std::make_unique<mainGameHUD>();
    std::unique_ptr<debugWindow> DebuggingWindow = nullptr;
public:

    debugWindow *getDebugWindowPtr() {
        return DebuggingWindow.get();
    }

    static UIManager& getInstance() {
        static UIManager instance;
        return instance;
    }
    UIManager() = default;
    ~UIManager() = default;

    UIManager* getUIManagerPtr() {
        return this;
    }

    void CreateDebugWindow(tgui::Gui& gui, player& player);

    void DestroyDebugWindow();


    void RenderMainGameHUD(tgui::Gui &gui, player &p, bool developermode);
    void UpdateTextSizes(float width, float height);

    void UpdateAllUI(player& p);

    void CleanAllUI();

    bool IsDebugWindowVisible() const {
        return DebuggingWindow && DebuggingWindow->getDebugWindow() != nullptr;
    }
};


#endif //NOTSIMPLEGAME_UIMANAGER_H