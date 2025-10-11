

#ifndef NOTSIMPLEGAME_BASICENEMY_H
#define NOTSIMPLEGAME_BASICENEMY_H
#include "entities/baseEntity.h"

class player;

class basicEnemy : public baseEntity {
private:

public:
    explicit basicEnemy(int localID);
    ~basicEnemy() override = default;

    virtual void Update(float deltaTime) override;

    void chasePlayer(sf::Shape &player, const float &deltaTime);
protected:
    void createRandomEnemyShape();

};


#endif //NOTSIMPLEGAME_BASICENEMY_H