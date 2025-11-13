
#ifndef NOTSIMPLEGAME_PLAYER_H
#define NOTSIMPLEGAME_PLAYER_H
#include <memory>
#include "inventory/playerEquipment.h"
#include "entities/baseEntity.h"

class playerEquipment;

class player : public baseEntity {
private: // Functions

    std::unique_ptr<playerEquipment> Equipment;

    void createPlayerShape();

    void handleMovement(float deltaTime);

    void setPlayerStats();

private:
    bool isMoving = false;

    std::string playerName = "Hero";

    int levelMax = 100;
    float EXP = 50.f;
    float EXP_MAX = 100.f;

    void levelUp();


public:
    explicit player(int localID = 0);
    ~player() override = default;

    virtual void Update(float deltaTime) override;


public: // Setters

    void setIsMoving(bool moving) {
        this->isMoving = moving;
    }

    void setEXP(float exp) {
        EXP = exp;
    }
    void setEXP_MAX(float exp_max) {
        EXP_MAX = exp_max;
    }

    void setPlayerName(std::string name) {
        playerName = name;
    }

public: // Getters

    bool getIsMoving() const {
        return this->isMoving;
    }
    float getEXP() const {
        return EXP;
    }
    float getEXP_MAX() const {
        return EXP_MAX;
    }

    std::string getPlayerName() const {
        return playerName;
    }
    playerEquipment &getEquipment() const {
        return *Equipment;
    }

};


#endif //NOTSIMPLEGAME_PLAYER_H