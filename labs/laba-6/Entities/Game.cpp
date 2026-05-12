#include "Game.h"

#include <iostream>

Game::Game(const std::string& processName, const bool isRunning, const std::string& startDate,
         const int participantCount, const bool requiresPhysical, const std::string& purpose,
         const int pMin, const int pMax, const std::string& r) : HumanActivity(processName, isRunning,
             startDate, participantCount, requiresPhysical, purpose) {
    playersMin = 0;
    playersMax = 0;
    setPlayersMin(pMin);
    setPlayersMax(pMax);
    setRules(r);
}

std::string Game::getProcessName() const {
    return processName;
}

Date Game::getStartDate() const {
    return startDate;
}

int Game::getPlayersMin() const {
    return playersMin;
}

int Game::getParticipantCount() const {
    return participantCount;
}



int Game::getPlayersMax() const {
    return playersMax;
}

std::string Game::getRules() const {
    return rules;
}

void Game::setRules(const std::string &r) {
    rules = r;
}

void Game::setPlayersMin(int p) {
    playersMin = p > 0 ? p : 1;
}

void Game::setPlayersMax(int p) {
    playersMax = p > 1 ? p : 2;
}

bool Game::isValidCount(const int count) const {
    return count >= playersMin && count <= playersMax;
}

void Game::print() {
    std::cout << "Game: " << processName
                  << " | игроков: "   << playersMin << "–" << playersMax
                  << " | правила: "   << rules;
}
