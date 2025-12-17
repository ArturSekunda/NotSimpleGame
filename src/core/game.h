
#ifndef NOTSIMPLEGAME_GAME_H
#define NOTSIMPLEGAME_GAME_H

#include "renderer.h"
#include "entities/player/player.h"
#include "entities/enemies/basicEnemy.h"
#include "managers/itemManager.h"
#include "entities/projectile/projectileEntity.h"
#include "managers/entitiesManager.h"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "managers/UIManager.h"



namespace sf {
    class View;
    class RenderWindow;
}

class UIManager;
class itemManager;

class game {

public:
    void Updater();

    sf::Clock WaveClock;
    sf::Clock WaveLabelClock;

    bool showWaveLabel = false;

    inline static int WaveCounter = 1;

public:
    game() = default;
    ~game() = default;

public: // Initialization and Getters

    void initializeEntities();

    void CreateNewEnemyWave(int enemyCount);

    renderer& getRenderer() {
        return *rendererInstance;
    }

    entitiesManager& getEntitiesManager() {
        return *entitiesManagerInstance;
    }

    bool DeveloperMode = true;

    // Delta Time Setter
    void setDeltaTime(float dt) {
        this->DeltaTime = dt;
    }

protected: // Debug and instantiates

    float DeltaTime;

    std::unique_ptr<renderer> rendererInstance;

    std::unique_ptr<entitiesManager> entitiesManagerInstance;

};


#endif //NOTSIMPLEGAME_GAME_H