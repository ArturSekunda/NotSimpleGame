//
// Created by lukas on 21.09.2025.
//

#include "debugHandler.h"

#include <iostream>

#include "entities/player/player.h"


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

bool debugHandler::getIsPlayerAlive() {
    return CurrentPlayerDebug ? CurrentPlayerDebug->getIsAlive() : false;
}

float debugHandler::getPlayerHealth() {
    return CurrentPlayerDebug ? CurrentPlayerDebug->getHealth() : 0.0f;
}

float debugHandler::getPlayerMaxHealth() {
    return CurrentPlayerDebug ? CurrentPlayerDebug->getMaxHealth() : 0.0f;
}

float debugHandler::getPlayerMana() {
    return CurrentPlayerDebug ? CurrentPlayerDebug->getMana() : 0.0f;
}

float debugHandler::getPlayerMaxMana() {
    return CurrentPlayerDebug ? CurrentPlayerDebug->getMaxMana() : 0.0f;
}

float debugHandler::getPlayerEXP() {
    return CurrentPlayerDebug ? CurrentPlayerDebug->getEXP() : 0.0f;
}

float debugHandler::getPlayerEXPMax() {
    return CurrentPlayerDebug ? CurrentPlayerDebug->getEXP_MAX() : 0.0f;
}

float debugHandler::getPlayerSpeed() {
    return CurrentPlayerDebug ? CurrentPlayerDebug->getSpeed() : 0.0f;
}

float debugHandler::getPlayerDefense() {
    return CurrentPlayerDebug ? CurrentPlayerDebug->getDefense() : 0.0f;
}

int debugHandler::getPlayerLevel() {
    return CurrentPlayerDebug ? CurrentPlayerDebug->getLevel() : 0;
}

std::string debugHandler::getPlayerName() {
    if (CurrentPlayerDebug) {
        return CurrentPlayerDebug->getPlayerName();
    }else {
        return "ERROR: No Player";
    }
}

baseStats debugHandler::getPlayerBaseStats() {
    return CurrentPlayerDebug ? CurrentPlayerDebug->getStats() : baseStats();
}

void debugHandler::setIsPlayerAlive(bool alive) {
    CurrentPlayerDebug->setIsAlive(alive);
}

void debugHandler::setPlayerHealth(float health) {
    CurrentPlayerDebug->setHealth(health);
}

void debugHandler::setPlayerMaxHealth(float maxHealth) {
    CurrentPlayerDebug->setMaxHealth(maxHealth);
}

void debugHandler::setPlayerMana(int mana) {
    CurrentPlayerDebug->setMana(mana);
}

void debugHandler::setPlayerMaxMana(int maxMana) {
    CurrentPlayerDebug->setMaxMana(maxMana);
}

void debugHandler::setPlayerEXP(float exp) {
    CurrentPlayerDebug->setEXP(exp);
}

void debugHandler::setPlayerEXPMax(float expMax) {
    CurrentPlayerDebug->setEXP_MAX(expMax);
}

void debugHandler::setPlayerSpeed(float speed) {
    CurrentPlayerDebug->setSpeed(speed);
}

void debugHandler::setPlayerDefense(float defense) {
    CurrentPlayerDebug->setDefense(defense);
}

void debugHandler::setPlayerLevel(int level) {
    CurrentPlayerDebug->setLevel(level);
}

void debugHandler::setPlayerName(const std::string &name) {
    CurrentPlayerDebug->setPlayerName(name);
}

void debugHandler::setPlayerBaseStats(const baseStats &stats) {
    CurrentPlayerDebug->setStats(stats);
}
