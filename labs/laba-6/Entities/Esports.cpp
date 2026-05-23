// Esports.cpp
#include "Esports.h"

#include <iomanip>

Esports::Esports(const std::string &processName, const bool isRunning, const std::string &startDate,
                 const int participantCount, const bool requiresPhysical, const std::string &purpose,
                 const int pMin, const int pMax, const std::string &r,
                 const std::string &gTitle, const std::string &pl, double pool,
                 const std::string &f, int mAge, bool isOl) : Game(processName, isRunning, startDate, participantCount, requiresPhysical, purpose, pMin, pMax, r),
                                                              CompetitiveSport(f, mAge, isOl) {
    gameTitle = gTitle;
    platform = pl;
    prizePool = pool;
}

bool Esports::isEligible(const int mAge) const {
    return CompetitiveSport::isEligible(mAge);
}

std::string Esports::getGameTitle() const {
    return gameTitle;
}

std::string Esports::getPlatform() const {
    return platform;
}

double Esports::getPrizePool() const {
    return prizePool;
}

void Esports::setPrizePool(const double prize) {
    prizePool = prize > 0.0 ? prize : 0.0;
}

void Esports::setGameTitle(const std::string &title) {
    gameTitle = title;
}

void Esports::setPlatform(const std::string &pl) {
    platform = pl;
}

void Esports::matchReport() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  ┌──────────────────────────────┐\n"
              << "  │        ОТЧЁТ О МАТЧЕ         │\n"
              << "  ├──────────────────────────────┤\n"
              << "  │ Турнир:      " << getProcessName()       << "\n"
              << "  │ Дата:        " << getStartDate().getDate()           << "\n"
              << "  │ Игра:        " << gameTitle         << "\n"
              << "  │ Платформа:   " << platform          << "\n"
              << "  │ Участников:  " << getParticipantCount()  << "\n"
              << "  │ Призовой:    " << prizePool        << "\n"
              << "  │ Федерация:   " << federation        << "\n"
              << "  │ Мин.возраст: " << minAge            << "\n"
              << "  │ Олимпийский: " << (isOlympic ? "да" : "нет") << "\n"
              << "  └──────────────────────────────┘\n";
}

void Esports::print() {
    std::cout << "Esports: " << getProcessName()
              << " | название игры: " << gameTitle
              << " | платформа: " << platform
              << " | призовой фонд: " << prizePool
              << " | федерация: " << federation << "\n";
}