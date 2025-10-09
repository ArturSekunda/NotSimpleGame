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
        DebuggingWindow.reset();
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

void UIManager::UpdateAllUI(player &p, float deltaTime) {
    timeSinceLastFrame += deltaTime;

    if (timeSinceLastFrame >= timeBetweenFrames) {

        if (DebuggingWindow) {

            if (DebuggingWindow->isPendingDestruction() == true) {
                DestroyDebugWindow();
                return;
            }

            if (DebuggingWindow->getDebugWindow() && DebuggingWindow->getDebugWindow()->isVisible()) {
                DebuggingWindow->update();
            }

        }

        MainGameHUD->UpdateUI(p);
        timeSinceLastFrame = 0.f;
    }
}

void UIManager::CleanAllUI() {

    std::cout << "DEBUG: UIManager::CleanAllUI() START\n";

    if (DebuggingWindow) {
        std::cout << "DEBUG: Cleaning DebuggingWindow\n";
        DebuggingWindow->CleanUp();
    }

    if (MainGameHUD) {
        std::cout << "DEBUG: Cleaning MainGameHUD\n";
        MainGameHUD->CleanUp();
    }

    std::cout << "DEBUG: UIManager::CleanAllUI() END\n";
}
