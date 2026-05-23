// Reader.cpp
#include "Reader.h"

#include <iostream>

int Reader::getId() const {
    return id;
}

std::string Reader::getFullName() const {
    return fullName;
}

void Reader::setId(int i) {
    id = i;
}

void Reader::setFullName(const std::string& n) {
    fullName = n;
}

void Reader::print() const {
    std::cout << "  " << fullName << ", билет №" << id << std::endl;
}