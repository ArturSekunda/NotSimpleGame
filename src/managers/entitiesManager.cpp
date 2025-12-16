#include "entitiesManager.h"

#include "inputManager.h"
#include "core/renderer.h"
#include "entities/enemies/basicEnemy.h"

entitiesManager::entitiesManager() {
    ItemManager = std::make_unique<itemManager>();
}

void entitiesManager::CreatePlayerOnStartup() {
    playerInstance = std::make_unique<player>(EntitiesIDCounter);
    ItemManager->CreateFirstWeaponForPlayer(*playerInstance);
    EntitiesIDCounter++;
}

void entitiesManager::CreateBasicEnemy(int enemyCount) {
    for (int i = 0; i < enemyCount; i++) {
        auto enemy = std::make_unique<basicEnemy>(EntitiesIDCounter, playerInstance->getLevel());
        ItemManager->CreateArmorForEnemy(*enemy);
        ItemManager->CreateWeaponForEnemy(*enemy);
        L_BasicEnemy.push_back(std::move(enemy));
        EntitiesIDCounter++;
    }
}

void entitiesManager::RemoveDeadBasicEnemies(const EntityID& EnemiesID) {
    auto it = std::remove_if(L_BasicEnemy.begin(), L_BasicEnemy.end(),
        [&EnemiesID](const std::unique_ptr<basicEnemy>& entity) {
            return entity->getEntityID().type == EnemiesID.type &&
                   entity->getEntityID().localID == EnemiesID.localID;
        });

    L_BasicEnemy.erase(it, L_BasicEnemy.end());
}

void entitiesManager::Updater(float DeltaTime, renderer& rendererInstance) {
    playerInstance->Update(DeltaTime);

    for (auto& enemy : L_BasicEnemy) {
        enemy->Update(DeltaTime);
        enemy->chasePlayer(getPlayerShape(), DeltaTime);
    }

    if (playerInstance->getEquipment().getWeaponSlot() != nullptr && rendererInstance.hasView()) {
        inputManager:: getInstance().isMouseButtonPressed(
            getPlayerShape().getPosition(),
            L_Projectile,
            rendererInstance.getView());
    }

    for (const auto& bullet: L_Projectile) {
        for (const auto& entity : L_BasicEnemy) {
            auto enemy = entity.get();
            if (enemy && bullet->getEntityBounds().intersects(entity->getEntityBounds())) {
                //std::cout << "Projectile hit Enemy ID: " << entity->getEntityID().toString() << "\n";
                if (enemy->DamageClock.getElapsedTime().asSeconds() >= 0.25f && playerInstance->getEquipment().getWeaponSlot() != nullptr) {
                    enemy->takeDamage(playerInstance->getEquipment().getWeaponSlot()->getDamage());
                    std::cout << "Player deals " << playerInstance->getEquipment().getWeaponSlot()->getDamage() << " damage.\n";
                    enemy->DamageClock.restart();
                    if (enemy->isDead(playerInstance->getInventory())) {
                        std::cout << "Enemy ID: " << entity->getEntityID().toString() << " is dead.\n";
                        RemoveDeadBasicEnemies(entity->getEntityID());
                        break;
                    }
                }
            }
        }
    }

    projectileEntity::updateProjectiles(DeltaTime, L_Projectile);
    projectileEntity::cleanupProjectiles(L_Projectile);
}

const player & entitiesManager::getPlayerPtr() const {
    return *playerInstance;
}

player& entitiesManager::getPlayerPtr() {
    return *playerInstance;
}

sf::Shape & entitiesManager::getPlayerShape() {
    if (!playerInstance) {
        throw std::runtime_error("Player not initialized");
    }
    auto shape = playerInstance->getEntityShape();
    if (!shape) {
        throw std::runtime_error("Player shape is null");
    }
    return *shape;
}

sf::RectangleShape & entitiesManager::getPlayerCollisionBox() {
    return *getPlayerPtr().getCollisionBox();
}
