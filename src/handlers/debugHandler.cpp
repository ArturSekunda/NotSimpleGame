//
// Created by lukas on 21.09.2025.
//

#include "debugHandler.h"

#include <iostream>


void debugHandler::ToggleDebug() {
    if (!isEnabled) {
        isEnabled = true;
        std::cout << "Debug mode enabled." << std::endl;
    } else {
        isEnabled = false;
        wantToShowCollisionBoxes = false;
        std::cout << "Debug mode disabled." << std::endl;

    }
}

void debugHandler::ShowCollisionBoxes() {
    if (!isEnabled) {
        std::cout << "Can't show collision boxes." << std::endl;
        return;
    }
    if (!wantToShowCollisionBoxes && isEnabled) {
        wantToShowCollisionBoxes = true;
        std::cout << "Collision boxes will be shown." << std::endl;
    } else {
        wantToShowCollisionBoxes = false;
        std::cout << "Collision boxes will be hidden." << std::endl;
    }
}
