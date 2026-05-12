#include "CompetitiveSport.h"

CompetitiveSport::CompetitiveSport(const std::string &f, int mAge, bool isOl) {
    federation = f;
    minAge = mAge > 0 ? mAge : 0;
    isOlympic = isOl;
}

std::string CompetitiveSport::getFederation() const {
    return federation;
}

int CompetitiveSport::getMinAge() const {
    return minAge;
}

bool CompetitiveSport::getIsOlympic()  const {
    return isOlympic;
}

void CompetitiveSport::setIsOlympic(const bool isOl) {
    isOlympic = isOl;
}

void CompetitiveSport::setMinAge(const int mAge) {
    minAge = mAge > 0 ? mAge : 0;
}

void CompetitiveSport::setFederation(const std::string &f) {
    federation = f;
}

bool CompetitiveSport::isEligible(const int age) const {
    return age >= minAge;
}

void CompetitiveSport::print() {
    std::cout << "CompetitiveSport:"
                  << " федерация="    << federation
                  << " | мин.возраст=" << minAge
                  << " | олимпийский=" << (isOlympic ? "да" : "нет");
}