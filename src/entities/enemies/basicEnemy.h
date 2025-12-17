

#ifndef NOTSIMPLEGAME_BASICENEMY_H
#define NOTSIMPLEGAME_BASICENEMY_H
#include "entities/baseEntity.h"
#include "inventory/enemyEquipment.h"
#include "managers/entitiesManager.h"

class enemyEquipment;
class player;

class basicEnemy : public baseEntity {

    enemyEquipment equipment;

    entitiesManager* EManager;

public:
    explicit basicEnemy(int localID,int playerLevel, sf::Vector2f playerPos, entitiesManager* entitiesManager);
    ~basicEnemy() override = default;

    float EXP = 0.f;

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