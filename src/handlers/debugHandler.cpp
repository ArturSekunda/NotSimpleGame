//
// Created by lukas on 21.09.2025.
//

#include "debugHandler.h"

#include <iostream>

#include "entities/player/player.h"


void debugHandler::ShowCollisionBoxes(){
    wantToShowCollisionBoxes = !wantToShowCollisionBoxes;
    std::cout << "Collision boxes toggled to: " << wantToShowCollisionBoxes << std::endl;
}

bool debugHandler::getIsPlayerAlive() {
    return CurrentPlayerDebug.getIsAlive();
}

float debugHandler::getPlayerHealth() {
    return CurrentPlayerDebug.getHealth();
}

float debugHandler::getPlayerMaxHealth() {
    return CurrentPlayerDebug.getMaxHealth();
}

float debugHandler::getPlayerMana() {
    return CurrentPlayerDebug.getMana();
}

float debugHandler::getPlayerMaxMana() {
    return CurrentPlayerDebug.getMaxMana();
}

float debugHandler::getPlayerEXP() {
    return CurrentPlayerDebug.getEXP();
}

float debugHandler::getPlayerEXPMax() {
    return CurrentPlayerDebug.getEXP_MAX();
}

float debugHandler::getPlayerSpeed() {
    return CurrentPlayerDebug.getSpeed();
}

float debugHandler::getPlayerDefense() {
    return CurrentPlayerDebug.getDefense();
}

int debugHandler::getPlayerLevel() {
    return CurrentPlayerDebug.getLevel();
}

sf::Vector2f debugHandler::getPlayerLocation() {
    return CurrentPlayerDebug.getPosition();
}

std::string debugHandler::getPlayerName() {
        return CurrentPlayerDebug.getPlayerName();
}

baseStats& debugHandler::getPlayerBaseStats() {
    return CurrentPlayerDebug.getStats();
}

void debugHandler::setIsPlayerAlive(bool alive) {
    CurrentPlayerDebug.setIsAlive(alive);
}

void debugHandler::setPlayerHealth(float health) {
    CurrentPlayerDebug.setHealth(health);
}

void debugHandler::setPlayerMaxHealth(float maxHealth) {
    CurrentPlayerDebug.setMaxHealth(maxHealth);
}

void debugHandler::setPlayerMana(int mana) {
    CurrentPlayerDebug.setMana(mana);
}

void debugHandler::setPlayerMaxMana(int maxMana) {
    CurrentPlayerDebug.setMaxMana(maxMana);
}

void debugHandler::setPlayerEXP(float exp) {
    CurrentPlayerDebug.setEXP(exp);
}

void debugHandler::setPlayerEXPMax(float expMax) {
    CurrentPlayerDebug.setEXP_MAX(expMax);
}

void debugHandler::setPlayerSpeed(float speed) {
    CurrentPlayerDebug.setSpeed(speed);
}

void debugHandler::setPlayerDefense(float defense) {
    CurrentPlayerDebug.setDefense(defense);
}

void debugHandler::setPlayerLevel(int level) {
    CurrentPlayerDebug.setLevel(level);
}

void debugHandler::setPlayerName(const std::string &name) {
    CurrentPlayerDebug.setPlayerName(name);
}

void debugHandler::setPlayerBaseStats(baseStats &stats) {
    CurrentPlayerDebug.setStats(stats);
}
