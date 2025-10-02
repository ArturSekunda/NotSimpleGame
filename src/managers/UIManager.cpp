#include "UIManager.h"

#include "entities/player/player.h"
#include "UI/mainGameHUD.h"

void UIManager::RenderMainGameHUD(tgui::Gui &gui, const player& p) {

    MainGameHUD->initializePanels(gui);
    MainGameHUD->initializeBars(p);
    MainGameHUD->DisplayPlayerNameAndLevel(p);
}

void UIManager::UpdateTextSizes(float width, float height){

    MainGameHUD->UpdateTextSizes(width, height);
}

void UIManager::UpdateAllUI(const player &p) {
    MainGameHUD->UpdateUI(p);
}

void UIManager::CleanAllUI() {

    MainGameHUD->CleanUp();
}
