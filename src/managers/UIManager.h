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
    std::unique_ptr<debugWindow> DebuggingWindow = std::make_unique<debugWindow>();
public:

    static UIManager& getInstance() {
        static UIManager instance;
        return instance;
    }
    UIManager() = default;
    ~UIManager() = default;



    void RenderMainGameHUD(tgui::Gui &gui, const player &p, bool DeveloperMode);

    void UpdateTextSizes(float width, float height);

    void UpdateAllUI(const player& p);

    void CleanAllUI();
};


#endif //NOTSIMPLEGAME_UIMANAGER_H