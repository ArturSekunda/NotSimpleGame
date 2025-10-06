//
// Created by lukas on 21.09.2025.
//

#include "debugHandler.h"

#include <iostream>


void debugHandler::ShowCollisionBoxes() {
    if (!wantToShowCollisionBoxes) {
        wantToShowCollisionBoxes = true;
        std::cout << "Collision boxes will be shown." << std::endl;
    } else {
        wantToShowCollisionBoxes = false;
        std::cout << "Collision boxes will be hidden." << std::endl;
    }
}

void debugHandler::CurrentPlayer(player &player) {
    CurrentPlayerDebug = &player;
}
