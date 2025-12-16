#ifndef NOTSIMPLEGAME_ENTITIESMANAGER_H
#define NOTSIMPLEGAME_ENTITIESMANAGER_H
#include <memory>

#include "itemManager.h"
#include "entities/player/player.h"
#include "entities/projectile/projectileEntity.h"


class renderer;

class entitiesManager {

    inline static int EntitiesIDCounter = 0;

    std::unique_ptr<itemManager> ItemManager;

    std::unique_ptr<player> playerInstance;



    std::vector<std::unique_ptr<basicEnemy>> L_BasicEnemy;

    std::vector<std::unique_ptr<projectileEntity>> L_Projectile;

public:
    entitiesManager();
    ~entitiesManager() = default;
    // Create a Player instance at the start of the game (Use it once)
    void CreatePlayerOnStartup();

    void CreateBasicEnemy(int enemyCount);

    void RemoveDeadBasicEnemies(const EntityID& EnemiesID);

    void Updater(float DeltaTime, renderer& rendererInstance);

    // Const version to only read player
    const player& getPlayerPtr() const;

    // Non-const version to modify player
    player& getPlayerPtr();

    sf::Shape& getPlayerShape();

    sf::RectangleShape& getPlayerCollisionBox();

    std::vector<std::unique_ptr<projectileEntity>>& getProjectiles() {
        return L_Projectile;
    }

    std::vector<std::unique_ptr<basicEnemy>>& getBasicEnemyList() {
        return L_BasicEnemy;
    }
};


#endif //NOTSIMPLEGAME_ENTITIESMANAGER_H