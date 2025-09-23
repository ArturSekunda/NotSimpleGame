
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

    std::vector<std::shared_ptr<basicEnemy>> getEnemyPtrTable();

    void addEnemyToList(const std::shared_ptr<basicEnemy>& enemy) {
        basicEnemies.push_back(enemy);
    }

    void decreaseEnemyFromList(size_t index);

    size_t getEnemyListSize() const { return basicEnemies.size(); }


    sf::Shape &getPlayerShape();

    // Getters for collision boxes
    sf::RectangleShape& getPlayerCollisionBox() {
        return *getPlayerPtr()->getCollisionBox();
    }

    // Delta Time Setter
    void setDeltaTime(float dt) {
        this->DeltaTime = dt;
    }

protected:
    float DeltaTime;

    std::vector<std::shared_ptr<basicEnemy>> basicEnemies;

    std::shared_ptr<player> playerInstance;

};


#endif //NOTSIMPLEGAME_GAME_H