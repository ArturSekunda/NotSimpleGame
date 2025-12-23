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

    if (! playerInstance) {
        std::cerr << "ERROR: playerInstance is NULL!  Cannot create enemies!" << std::endl;
        return;
    }

    for (int i = 0; i < enemyCount; i++) {

        auto enemy = std::make_unique<basicEnemy>(EntitiesIDCounter, playerInstance->getLevel(), playerInstance->getEntityShape()->getPosition(), this);


        ItemManager->CreateArmorForEnemy(*enemy);

        ItemManager->CreateWeaponForEnemy(*enemy);

        L_BasicEnemy.push_back(std::move(enemy));

        EntitiesIDCounter++;
    }
}

void entitiesManager::RemoveDeadBasicEnemies(const EntityID& EnemiesID) {
    auto it = std::ranges::remove_if(L_BasicEnemy, [&EnemiesID](const std::unique_ptr<basicEnemy>& entity)
        {
            return entity->getEntityID().type == EnemiesID.type && entity->getEntityID().localID == EnemiesID.localID;
        }).begin();

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

    std:: vector<EntityID> enemiesToRemove;

    for (const auto& bullet: L_Projectile) {
        for (const auto& entity : L_BasicEnemy) {
            auto enemy = entity.get();
            if (enemy && bullet->getEntityBounds().intersects(entity->getEntityBounds())) {
                if (enemy->DamageClock.getElapsedTime().asSeconds() >= 0.25f
                    && playerInstance->getEquipment().getWeaponSlot() != nullptr) {

                    enemy->takeDamage(playerInstance->getEquipment().getWeaponSlot()->getDamage() + playerInstance->getStats().strength);
                    std::cout << "Player deals " << playerInstance->getEquipment().getWeaponSlot()->getDamage() << " damage.\n";
                    enemy->DamageClock.restart();

                    if (enemy->isDead(playerInstance->getInventory())) {
                        playerInstance->levelUp(enemy->EXP);
                        std::cout << "Enemy ID: " << entity->getEntityID().toString() << " is dead.\n";
                        enemiesToRemove.push_back(entity->getEntityID());
                        break;
                    }
                    }
            }
        }
    }

    for (const auto& enemyID : enemiesToRemove) {
        RemoveDeadBasicEnemies(enemyID);
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
