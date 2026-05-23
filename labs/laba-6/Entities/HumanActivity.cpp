// HumanActivity.cpp
#include "HumanActivity.h"

#include <iostream>

HumanActivity::HumanActivity(const std::string &name, const bool isRunning,
    const std::string &startDate, const int pCount, const bool requires_physical,
    const std::string &purp) : Process(name, isRunning, startDate) {
    participantCount = 0;
    setParticipantCount(pCount);
    requiresPhysical = requires_physical;
    purpose = purp;
}

int HumanActivity::getParticipantCount() const {
    return participantCount;
}

bool HumanActivity::getRequiresPhysical() const {
    return requiresPhysical;
}

string HumanActivity::getPurpose() const {
    return purpose;
}

void HumanActivity::setParticipantCount(int participant_count) {
    participantCount = participant_count;
}

void HumanActivity::setRequiresPhysical(bool requires_physical) {
    requiresPhysical = requires_physical;
}

void HumanActivity::setPurpose(const string &purposeStr) {
    purpose = purposeStr;
}

std::string HumanActivity::getDescription() const {
    return processName +
        " | участников: " + std::to_string(participantCount)
         + " | цель: " + purpose
         + " | требуется физическая нагрузка: "  + (requiresPhysical ? "да " : "нет ");
}

void HumanActivity::print() {
    std::cout << "Человеческая деятельность: " << getDescription() <<
        (isRunning ? std::string(" | Дата запуска: ").append(startDate.getDate()) : "");
}