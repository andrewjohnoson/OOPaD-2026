// Organisation.cpp
#include "Organisation.h"

std::string Organisation::getOrgName() const {
    return orgName;
}

std::string Organisation::getAddress() const {
    return address;
}

void Organisation::setOrgName(const std::string &n) {
    orgName = n;
}

void Organisation::setAddress(const std::string &a) {
    address = a;
}

void Organisation::print() const {
    std::cout << "  Организация: " << orgName
              << ", адресс: " << address << std::endl;
}