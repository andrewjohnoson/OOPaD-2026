// Employee.cpp
#include "Employee.h"

#include <iostream>

Employee::~Employee() {
    if (currentSub) {
        currentSub->unlock();
        currentSub = nullptr;
    }
}

int Employee::getId() const {
    return id;
}

std::string Employee::getFullName() const {
    return fullName;
}

std::string Employee::getPosition() const {
    return position;
}

Subscription* Employee::getCurrentSub() const {
    return currentSub;
}

void Employee::setId(const int i) {
    id = i;
}

void Employee::setFullName(const std::string& n) {
    fullName = n;
}

void Employee::setPosition(const std::string& p) {
    position = p;
}

void Employee::takeSubscription(Subscription* sub) {
    if (currentSub) {
        releaseSubscription();
    }
    currentSub = sub;
    currentSub->lock();
    std::cout << "  Сотрудник \"" << fullName << "\" взял абонемент ["
              << sub->getId() << "] в работу." << std::endl;
}

void Employee::releaseSubscription() {
    if (currentSub) {
        currentSub->unlock();
        std::cout << "  Сотрудник \"" << fullName << "\" освободил абонемент ["
                  << currentSub->getId() << "]." << std::endl;
        currentSub = nullptr;
    }
}

void Employee::print() const {
    std::cout << "  [" << id << "] " << fullName
              << ", должность: " << position
              << ", работает с абонементом: "
              << (currentSub ? std::to_string(currentSub->getId()) : "нет") << "\n";
}