

#include "game.h"
#include "handlers/collisionHandler.h"

#include <iostream>
#include <memory>

#include "managers/UIManager.h"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

#include "managers/inputManager.h"

// Initialize player and enemy instances
void game::initializeEntities() {

    entitiesManagerInstance = std::make_unique<entitiesManager>();
    rendererInstance = std::make_unique<renderer>();

    entitiesManagerInstance->CreatePlayerOnStartup();
    entitiesManagerInstance->CreateBasicEnemy(3);

    rendererInstance->getUIManager().setHolderPlayerForHUD(entitiesManagerInstance->getPlayerPtr());

}

// Update game logic, player and enemy states
void game::Updater() {

    // Update player
    entitiesManagerInstance->Updater(DeltaTime, *rendererInstance);

    // Update UI
    rendererInstance->getUIManager().UpdateAllUI(entitiesManagerInstance->getPlayerPtr(), DeltaTime);

    // Collision Detection
    std::vector<basicEnemy*> collidingEnemies = collisionHandler::getInstance().checkAllCollisions(entitiesManagerInstance->getPlayerShape(), entitiesManagerInstance->getBasicEnemyList());

    // Handle Collisions
    for (const auto& enemyIDStr: collidingEnemies) {
        auto enemy = dynamic_cast<basicEnemy*>(enemyIDStr);
        if (enemy) {
            if (entitiesManagerInstance->getPlayerPtr().DamageClock.getElapsedTime().asSeconds() >= 0.5f) {
                entitiesManagerInstance->getPlayerPtr().takeDamage(enemy->getEquipment().getWeaponSlot()->getDamage());
                std::cout << "Enemy ID: " << enemy->getEntityID().toString() << " deals " << enemy->getEquipment().getWeaponSlot()->getDamage() << " damage to Player.\n";
                entitiesManagerInstance->getPlayerPtr().DamageClock.restart();
            }
        }
    }

}

