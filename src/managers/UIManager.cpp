#include "UIManager.h"

#include "entities/player/player.h"
#include "UI/mainGameHUD.h"

void UIManager::RenderMainGameHUD(tgui::Gui &gui, player p) {

    mainGameHUD::getInstance().initializePanels(gui);
    mainGameHUD::getInstance().initializeBars(p);
}

void UIManager::UpdateTextSizes(float width, float height){

    mainGameHUD::getInstance().UpdateTextSizes(width, height);
}

void UIManager::CleanAllUI() {

    mainGameHUD::getInstance().CleanUp();
}
