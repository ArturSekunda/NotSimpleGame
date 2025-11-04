
#ifndef NOTSIMPLEGAME_DEBUGHANDLER_H
#define NOTSIMPLEGAME_DEBUGHANDLER_H
#include <string>

#include "SFML/System/Vector2.hpp"


struct baseStats;
class player;

class debugHandler {
private:
    player& CurrentPlayerDebug;

    bool wantToShowCollisionBoxes = false;
public:

    explicit debugHandler(player& player) : CurrentPlayerDebug(player) {};
    ~debugHandler() = default;

    void ShowCollisionBoxes();



    //Getters
    bool getWantToShowCollisionBoxes() const { return wantToShowCollisionBoxes; }
    bool getIsPlayerAlive();
    float getPlayerHealth();
    float getPlayerMaxHealth();
    float getPlayerMana();
    float getPlayerMaxMana();
    float getPlayerEXP();
    float getPlayerEXPMax();
    float getPlayerSpeed();
    float getPlayerDefense();
    int getPlayerLevel();
    sf::Vector2f getPlayerLocation();
    std::string getPlayerName();

    baseStats& getPlayerBaseStats();



    // Setters
    void setWantToShowCollisionBoxes(bool show) { wantToShowCollisionBoxes = show; }
    void setIsPlayerAlive(bool alive);
    void setPlayerHealth(float health);
    void setPlayerMaxHealth(float maxHealth);
    void setPlayerMana(int mana);
    void setPlayerMaxMana(int maxMana);
    void setPlayerEXP(float exp);
    void setPlayerEXPMax(float expMax);
    void setPlayerSpeed(float speed);
    void setPlayerDefense(float defense);
    void setPlayerLevel(int level);
    void setPlayerName(const std::string& name);
    void setPlayerBaseStats(baseStats& stats);
};


#endif //NOTSIMPLEGAME_DEBUGHANDLER_H