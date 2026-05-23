// BuildingMaterial.cpp
#include "BuildingMaterial.h"

#include <iostream>
#include <iomanip>

BuildingMaterial::BuildingMaterial(const int id, const std::string& name, const double price,
                     const int stock, const std::string& unit)
        : Product(id, name, price, stock), unit_(unit) {
    std::cout << "[CTOR] BuildingMaterial: \"" << name << "\"" << std::endl;
}

BuildingMaterial::~BuildingMaterial() {
    std::cout << "[DTOR] BuildingMaterial: \"" << name_ << "\"" << std::endl;
}

const std::string &BuildingMaterial::getUnit() const {
    return unit_;
}

std::string BuildingMaterial::getCategory() const {
    return "Стройматериал";
}

void BuildingMaterial::print() const {
    std::cout << "[" << id_ << "] "
              << std::left << std::setw(28) << name_
              << std::right << std::setw(8) << price_ << " руб./" << unit_
              << "  (остаток: " << stock_ << " " << unit_ << ")" << std::endl;
}