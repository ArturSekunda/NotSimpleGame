
#ifndef NOTSIMPLEGAME_PLAYER_H
#define NOTSIMPLEGAME_PLAYER_H
#include "entities/baseEntity.h"


class player : public baseEntity {
private:
    void createPlayerShape();
    sf::RectangleShape createCollisionBox();
public:
    player();
    ~player() override = default;

};


#endif //NOTSIMPLEGAME_PLAYER_H