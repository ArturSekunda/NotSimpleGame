

#include "game.h"
#include "handlers/collisionHandler.h"

#include <iostream>
#include <memory>
#include <thread>

#include "managers/UIManager.h"
#include <TGUI/TGUI.hpp>

#include "managers/inputManager.h"

// Initialize player and enemy instances
void game::initializeEntities() {

    entitiesManagerInstance = std::make_unique<entitiesManager>();
    rendererInstance = std::make_unique<renderer>();
    rendererInstance->getUIManager().getMainGameHUD().SetHolderEntitiesManager(*entitiesManagerInstance);

    entitiesManagerInstance->CreatePlayerOnStartup();

    rendererInstance->getUIManager().setHolderPlayerForHUD(entitiesManagerInstance->getPlayerPtr());

}

void game::CreateNewEnemyWave(int enemyCount) {

    rendererInstance->getUIManager().getMainGameHUD()
        .getWaveCounterWidget().UpdateWaveLabel(WaveCounter, true);

    WaveLabelClock.restart();
    showWaveLabel = true;

    entitiesManagerInstance->CreateBasicEnemy(enemyCount);
    WaveCounter++;
}

// Update game logic, player and enemy states
void game::Updater() {

    // Update player
    entitiesManagerInstance->Updater(DeltaTime, *rendererInstance);

    // Update UI
    rendererInstance->getUIManager().UpdateAllUI(entitiesManagerInstance->getPlayerPtr(), DeltaTime);

    // Collision Detection
    std::vector<basicEnemy*> collidingEnemies = collisionHandler::getInstance().checkAllCollisions(entitiesManagerInstance->getPlayerShape(), entitiesManagerInstance->getBasicEnemyList());

    if (showWaveLabel && WaveLabelClock.getElapsedTime().asSeconds() >= 3.0f) {
        rendererInstance->getUIManager().getMainGameHUD()
            .getWaveCounterWidget().UpdateWaveLabel(WaveCounter, false);
        showWaveLabel = false;
    }

    if (WaveClock.getElapsedTime().asSeconds() >= 40.0f || WaveCounter == 1) {
        std::cout << "Spawning new enemy wave.. .\n";
        if (WaveCounter % 5 == 0) {
            std::cout << "Boss Wave Incoming!\n";
            // For simplicity, boss wave spawns double the enemies
            CreateNewEnemyWave((3 + WaveCounter) * 2);
        } else {
            CreateNewEnemyWave(5 + WaveCounter);
        }
        WaveClock.restart();
    }

    // Handle Collisions
    for (const auto& enemy: collidingEnemies) {
        if (enemy) {
            if (entitiesManagerInstance->getPlayerPtr().DamageClock.getElapsedTime().asSeconds() >= 0.5f) {
                entitiesManagerInstance->getPlayerPtr().takeDamage(enemy->getEquipment().getWeaponSlot()->getDamage());
                std::cout << "Enemy ID: " << enemy->getEntityID().toString() << " deals " << enemy->getEquipment().getWeaponSlot()->getDamage() << " damage to Player.\n";
                entitiesManagerInstance->getPlayerPtr().DamageClock.restart();
            }
        }
    }

}