
#ifndef NOTSIMPLEGAME_DEBUGHANDLER_H
#define NOTSIMPLEGAME_DEBUGHANDLER_H

namespace sf {

    class RenderWindow;

}

class debugHandler {

    debugHandler() = default;

    bool isEnabled = false;
    bool wantToShowCollisionBoxes = false;
public:
    static debugHandler& getInstance() {
        static debugHandler instance;
        return instance;
    }

    void ToggleDebug();
    void ShowCollisionBoxes();

    //Getters
    bool getIsEnabled() const { return isEnabled; }
    bool getWantToShowCollisionBoxes() const { return wantToShowCollisionBoxes; }
};


#endif //NOTSIMPLEGAME_DEBUGHANDLER_H