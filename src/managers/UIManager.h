#pragma once

#include <TGUI/Backend/SFML-Graphics.hpp>


class mainGameHUD;
class gameMenu;
class player;

#ifndef NOTSIMPLEGAME_UIMANAGER_H
#define NOTSIMPLEGAME_UIMANAGER_H


class UIManager {
public:

    static UIManager& getInstance() {
        static UIManager instance;
        return instance;
    }

    void RenderMainGameHUD(tgui::Gui& gui, player p);

    void UpdateTextSizes(float width, float height);

    void CleanAllUI();
};


#endif //NOTSIMPLEGAME_UIMANAGER_H