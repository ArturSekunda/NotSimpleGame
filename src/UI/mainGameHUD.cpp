#include "mainGameHUD.h"
#include "debugWindow.h"
#include "entities/player/player.h"
#include "managers/UIManager.h"
#include "MainGameHUDWidgets/playerEquipmentWidget.h"
#include "managers/entitiesManager.h"


void mainGameHUD::CleanUp() {
    {
        ProgressBars.reset();
        PanelsLayouts.reset();
        PlayerNameLevel.reset();
        PlayerStats.reset();
        EquipmentWidget.reset();
        InventoryWidget.reset();
        WaveCounterWidget.reset();
        Mouse.Destroy();

        DebugButtonForWindow = nullptr;
    }
}


void mainGameHUD::createHUD(tgui::Gui &gui) {
    ProgressBars = std::make_unique<playerProgressBars>();
    PanelsLayouts = std::make_unique<panelsWithLayouts>();
    PlayerNameLevel = std::make_unique<playerNameAndLevel>();
    PlayerStats = std::make_unique<playerStats>();
    EquipmentWidget = std::make_unique<playerEquipmentWidget>();
    InventoryWidget = std::make_unique<playerInventoryWidget>();
    WaveCounterWidget = std::make_unique<waveCounter>();

    PanelsLayouts->CombineAll(gui);
    PlayerNameLevel->initializeLabels(PanelsLayouts->Layouts["PlayerNameEXPLayout"]->cast<tgui::VerticalLayout>());
    ProgressBars->initializeBars(PanelsLayouts->Layouts["StatsLayout"]->cast<tgui::VerticalLayout>());
    PlayerStats->initializeLabels(PanelsLayouts->Layouts["GridStats"]->cast<tgui::Grid>());
    EquipmentWidget->initializeIcons(PanelsLayouts->Panels["S_EquipmentPanel"]->cast<tgui::Panel>());
    InventoryWidget->initializeIcons(PanelsLayouts->Panels["S_InventoryPanel"]->cast<tgui::Panel>());
    WaveCounterWidget->initializeLabel(PanelsLayouts->Layouts["WaveCounter"]->cast<tgui::VerticalLayout>());
    Mouse.Initialize(PanelsLayouts->Panels["MainPanel"]->cast<tgui::Panel>());
    InventoryWidget->UIInventory(HolderPlayer->getInventory(), Mouse);
    EquipmentWidget->UIEquipment(HolderPlayer->getEquipment(), *HolderPlayer, Mouse);

    std::shared_ptr<tgui::Panel> DropPanel = PanelsLayouts->Panels["C_DropItemPanel"]->cast<tgui::Panel>();

    DropPanel->onClick([this]() {
        HolderEntitiesManager->removeItemFromDatabase(Mouse.itemPointer);
        Mouse.Clear();
    });


}


void mainGameHUD::initializeDebugButtons(tgui::Gui &gui, UIManager* uiManager, player& player) {
    // Create Debug Button
    DebugButtonForWindow = tgui::Button::create("Debug");
    if (!DebugButtonForWindow) {
        throw std::runtime_error("Failed to create debug button");
    }

    DebugButtonForWindow->setSize("10%", "10%");
    DebugButtonForWindow->setPosition("5%", "85%");
    DebugButtonForWindow->getRenderer()->setBackgroundColor(tgui::Color(100, 100, 100, 200));
    DebugButtonForWindow->getRenderer()->setTextColor(tgui::Color::White);

    DebugButtonForWindow->onPress([&gui, uiManager, &player]() {
        uiManager->CreateDebugWindow(gui, player);
    });
    gui.add(DebugButtonForWindow);

}


void mainGameHUD::UpdateUI(player &p) {
    Mouse.UpdatePosition();
    PlayerNameLevel->UpdateLabels(p.getPlayerName(), p.getLevel());
    ProgressBars->UpdateBars(p);
    PlayerStats->UpdateLabels(p.getStats());
    InventoryWidget->UpdateUISlots(p.getInventory());
    EquipmentWidget->UpdateUISlots(p.getEquipment().getArmorSlots(), p.getEquipment().getWeaponSlot());
}


void mainGameHUD::UpdateTextSizes(float width, float height) {
    PlayerNameLevel->UpdateTextSizes(width, height);
    ProgressBars->UpdateTextSize(width, height);
    PlayerStats->UpdateTextSizes(width, height);
    WaveCounterWidget->UpdateTextSize(width, height);


}
