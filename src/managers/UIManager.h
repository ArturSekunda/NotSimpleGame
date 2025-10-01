#pragma once

#include <TGUI/Backend/SFML-Graphics.hpp>

class mainGameHUD;
class gameMenu;

#ifndef NOTSIMPLEGAME_UIMANAGER_H
#define NOTSIMPLEGAME_UIMANAGER_H


class UIManager {
public:

    static UIManager& getInstance() {
        static UIManager instance;
        return instance;
    }

    void RenderMainGameHUD(tgui::Gui& gui);
};


#endif //NOTSIMPLEGAME_UIMANAGER_H