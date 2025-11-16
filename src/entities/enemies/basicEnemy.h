

#ifndef NOTSIMPLEGAME_BASICENEMY_H
#define NOTSIMPLEGAME_BASICENEMY_H
#include "entities/baseEntity.h"
#include "inventory/enemyEquipment.h"

class enemyEquipment;
class player;

class basicEnemy : public baseEntity {

    enemyEquipment equipment;

public:
    explicit basicEnemy(int localID);
    ~basicEnemy() override = default;

    virtual void Update(float deltaTime) override;

    void chasePlayer(sf::Shape &player, const float &deltaTime);

    bool isDead(Inventory& playerInventory);

    enemyEquipment &getEquipment() {
        return equipment;
    }
protected:
    void createRandomEnemyShape();

};


#endif //NOTSIMPLEGAME_BASICENEMY_H