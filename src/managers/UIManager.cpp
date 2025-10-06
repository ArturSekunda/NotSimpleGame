#include "UIManager.h"

#include "entities/player/player.h"
#include "UI/mainGameHUD.h"


void UIManager::CreateDebugWindow(tgui::Gui &gui, player &player) {
    if (!DebuggingWindow) {
        DebuggingWindow = std::make_unique<debugWindow>();
    }

    if (DebuggingWindow->getDebugWindow() == nullptr) {
        DebuggingWindow->initializeDebugWindow(gui, player);
    }
}

void UIManager::DestroyDebugWindow() {
    if (DebuggingWindow) {
        DebuggingWindow->CleanUp();
        DebuggingWindow = nullptr;
    }
}

void UIManager::RenderMainGameHUD(tgui::Gui &gui, player& p, bool developermode) {

    MainGameHUD->initializePanels(gui);
    MainGameHUD->initializeBars();
    MainGameHUD->DisplayPlayerNameAndLevel(p);

    if (developermode) {
        MainGameHUD->initializeDebugButtons(gui, getUIManagerPtr(), p);
    }
}

void UIManager::UpdateTextSizes(float width, float height){
    MainGameHUD->UpdateTextSizes(width, height);
}

void UIManager::UpdateAllUI(player &p) {
    MainGameHUD->UpdateUI(p);

}

void UIManager::CleanAllUI() {

    DebuggingWindow->CleanUp();
    MainGameHUD->CleanUp();
}
