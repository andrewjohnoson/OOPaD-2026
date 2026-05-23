// Process.cpp
#include "Process.h"

#include <iostream>

void Process::setStartDate(const std::string &date) {
    startDate.setDate(date);
}

void Process::setIsRunning(const bool running) {
    isRunning = running;
}

void Process::setProcessName(const string &name) {
    processName = name;
}

Date Process::getStartDate() const {
    return startDate;
}

bool Process::getIsRunning() const {
    return isRunning;
}

std::string Process::getProcessName() const {
    return processName;
}

void Process::start() {
    isRunning = true;
}

void Process::stop() {
    isRunning = false;
}

void Process::print() {
    std::cout << "Процесс: " << processName << " | запущен: "
            << (isRunning ? "да " : "нет") << (isRunning ? std::string(" | Дата запуска: ").append(startDate.getDate()) : "");
}

