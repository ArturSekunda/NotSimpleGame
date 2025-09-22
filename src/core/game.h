
#ifndef NOTSIMPLEGAME_GAME_H
#define NOTSIMPLEGAME_GAME_H

#include "entities/player/player.h"
#include "entities/enemies/basicEnemy.h"
#include <SFML/Graphics.hpp>


class game {
public:
    void Updater();

public:
    game() = default;
    ~game() = default;

    static game& getInstance() {
        static game instance;
        return instance;
    }

    void initializeEntities();

    std::shared_ptr<player> getPlayerPtr();
    std::shared_ptr<basicEnemy> getEnemyPtr();


    sf::Shape &getEnemyShape();

    sf::Shape &getPlayerShape();

    // Getters for collision boxes
    sf::RectangleShape& getPlayerCollisionBox() {
        return *getPlayerPtr()->getCollisionBox();
    }

    sf::RectangleShape& getEnemyCollisionBox() {
        return *getEnemyPtr()->getCollisionBox();
    }

    // Delta Time Setter
    void setDeltaTime(float dt) {
        this->DeltaTime = dt;
    }

protected:
    float DeltaTime;

    std::shared_ptr<player> playerInstance;
    std::shared_ptr<basicEnemy> enemyInstance;


};


#endif //NOTSIMPLEGAME_GAME_H