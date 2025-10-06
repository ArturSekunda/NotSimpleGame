
#ifndef NOTSIMPLEGAME_DEBUGHANDLER_H
#define NOTSIMPLEGAME_DEBUGHANDLER_H
#include <string>

#include "managers/statsManager.h"


class player;

class debugHandler {
private:


private:
    player* CurrentPlayerDebug = nullptr;

    bool wantToShowCollisionBoxes = false;

    bool DeveloperMode = false;
public:
    static debugHandler& getInstance() {
        static debugHandler instance;
        return instance;
    }

    debugHandler() = default;
    ~debugHandler() = default;

    void ShowCollisionBoxes();



    //Getters
    bool getWantToShowCollisionBoxes() const { return wantToShowCollisionBoxes; }
    bool getDeveloperMode() const { return DeveloperMode; }
    void CurrentPlayer(player &player);
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
    std::string getPlayerName();
    baseStats getPlayerBaseStats();



    // Setters
    void setDeveloperMode(bool mode) { DeveloperMode = mode; }
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
    void setPlayerBaseStats(const baseStats& stats);
};


#endif //NOTSIMPLEGAME_DEBUGHANDLER_H