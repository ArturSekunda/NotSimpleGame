//
// Created by Artur on 1.10.2025.
//

#include "UIManager.h"

#include "UI/mainGameHUD.h"

void UIManager::RenderMainGameHUD(tgui::Gui &gui) {
    mainGameHUD::getInstance().initializePanels(gui);
}
