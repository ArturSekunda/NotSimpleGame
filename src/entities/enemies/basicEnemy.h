//
// Created by lukas on 22.09.2025.
//

#ifndef NOTSIMPLEGAME_BASICENEMY_H
#define NOTSIMPLEGAME_BASICENEMY_H
#include "entities/baseEntity.h"

class player;

class basicEnemy : public baseEntity {
private:

public:
    basicEnemy();
    ~basicEnemy() override = default;

    virtual void Update(float deltaTime) override;

    void chasePlayer(sf::Shape &player, const float &deltaTime);
protected:
    void createRandomEnemyShape();

};


#endif //NOTSIMPLEGAME_BASICENEMY_H