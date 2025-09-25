
#ifndef NOTSIMPLEGAME_PLAYER_H
#define NOTSIMPLEGAME_PLAYER_H
#include "managers/inputManager.h"
#include "entities/baseEntity.h"


class player : public baseEntity {
private: // Functions

    void createPlayerShape();

    void handleMovement(float deltaTime);

    void setPlayerStats();

private:
    bool isMoving = false;

public:
    explicit player(int localID = 0);
    ~player() override = default;

    virtual void Update(float deltaTime) override;


public: // Setters

    void setIsMoving(bool moving) {
        this->isMoving = moving;
    }
public: // Getters

    bool getIsMoving() const {
        return this->isMoving;
    }

};


#endif //NOTSIMPLEGAME_PLAYER_H