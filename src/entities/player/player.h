
#ifndef NOTSIMPLEGAME_PLAYER_H
#define NOTSIMPLEGAME_PLAYER_H
#include "managers/inputManager.h"
#include "entities/baseEntity.h"
#include "managers/statsManager.h"


struct baseStats;

class player : public baseEntity {
private: // Functions

    void createPlayerShape();

    void handleMovement(float deltaTime);

    void setPlayerStats();

private:
    bool isMoving = false;

    int level = 1;

    int levelMax = 10;
    float EXP = 100.f;
    float EXP_MAX = 100.f;

    baseStats stats;

public:
    explicit player(int localID = 0);
    ~player() override = default;

    virtual void Update(float deltaTime) override;


public: // Setters

    void setIsMoving(bool moving) {
        this->isMoving = moving;
    }

    void setLevel(int level) {
        this->level = level;
    }
    void setEXP(float exp) {
        EXP = exp;
    }
    void setEXP_MAX(float exp_max) {
        EXP_MAX = exp_max;
    }
    void setStats(baseStats stats) {
        this->stats = stats;
    }

public: // Getters

    bool getIsMoving() const {
        return this->isMoving;
    }
    int getLevel() const {
        return this->level;
    }
    float getEXP() const {
        return EXP;
    }
    float getEXP_MAX() const {
        return EXP_MAX;
    }
    baseStats getStats() const {
        return stats;
    }

};


#endif //NOTSIMPLEGAME_PLAYER_H