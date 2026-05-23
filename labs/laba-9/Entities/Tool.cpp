// Tool.cpp
#include "Tool.h"

#include <iomanip>
#include <iostream>

Tool::Tool(const int id, const std::string& name, const double price, const int stock, const std::string& brand)
    : Product(id, name, price, stock), brand_(brand) {
    std::cout << "[CTOR] Tool: \"" << name << "\"" << std::endl;
}

Tool::~Tool() {
    std::cout << "[DTOR] Tool: \"" << name_ << "\"" << std::endl;
}

const std::string& Tool::getBrand() const {
    return brand_;
}

std::string Tool::getCategory() const {
    return "Инструмент";
}

void Tool::print() const {
    std::cout << "[" << id_ << "] "
              << std::left << std::setw(28) << (name_ + " [" + brand_ + "]")
              << std::right << std::setw(8) << price_ << " руб."
              << "  (остаток: " << stock_ << ")" << std::endl;
}
