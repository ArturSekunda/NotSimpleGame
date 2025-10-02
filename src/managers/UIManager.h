#pragma once

#include <TGUI/Backend/SFML-Graphics.hpp>

#include "UI/mainGameHUD.h"


class mainGameHUD;
class gameMenu;
class player;

#ifndef NOTSIMPLEGAME_UIMANAGER_H
#define NOTSIMPLEGAME_UIMANAGER_H


class UIManager {
private:
    std::unique_ptr<mainGameHUD> MainGameHUD = std::make_unique<mainGameHUD>();
public:

    static UIManager& getInstance() {
        static UIManager instance;
        return instance;
    }
    UIManager() = default;
    ~UIManager() = default;



    void RenderMainGameHUD(tgui::Gui &gui, const player &p);

    void UpdateTextSizes(float width, float height);

    void UpdateAllUI(const player& p);

    void CleanAllUI();
};


#endif //NOTSIMPLEGAME_UIMANAGER_H