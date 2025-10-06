
#ifndef NOTSIMPLEGAME_DEBUGHANDLER_H
#define NOTSIMPLEGAME_DEBUGHANDLER_H


class player;

class debugHandler {

    debugHandler() = default;
    ~debugHandler() = default;

private:


private:
    player* CurrentPlayerDebug = nullptr;

    bool wantToShowCollisionBoxes = false;
public:
    static debugHandler& getInstance() {
        static debugHandler instance;
        return instance;
    }

    void ShowCollisionBoxes();
    void ShowPlayerInfo();
    void ShowPlayerSkillStatsInfo();
    void ChangePlayerStat();
    void ChangePlayerSkillStat();



    //Getters
    bool getWantToShowCollisionBoxes() const { return wantToShowCollisionBoxes; }
    void CurrentPlayer(player &player);
};


#endif //NOTSIMPLEGAME_DEBUGHANDLER_H