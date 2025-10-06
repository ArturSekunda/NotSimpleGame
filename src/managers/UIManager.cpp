#include "UIManager.h"

#include "entities/player/player.h"
#include "UI/mainGameHUD.h"


void UIManager::RenderMainGameHUD(tgui::Gui &gui, const player& p, bool DeveloperMode) {

    MainGameHUD->initializePanels(gui);
    MainGameHUD->initializeBars();
    MainGameHUD->DisplayPlayerNameAndLevel(p);

    // Initialize debug buttons only if in developer mode
    if (DeveloperMode) {
        MainGameHUD->initializeDebugButtons(gui, *DebuggingWindow);
    }


}

void UIManager::UpdateTextSizes(float width, float height){
    MainGameHUD->UpdateTextSizes(width, height);
}

void UIManager::UpdateAllUI(const player &p) {
    MainGameHUD->UpdateUI(p);
}

void UIManager::CleanAllUI() {

    DebuggingWindow->CleanUp();
    MainGameHUD->CleanUp();
}
