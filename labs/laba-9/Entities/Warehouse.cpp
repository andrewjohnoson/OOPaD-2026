// Warehouse.cpp
#include "Warehouse.h"

#include <iostream>

void Warehouse::addProduct(Product* p) {
    products_.push_back(p);
}

Product* Warehouse::findProduct(const std::string& name) const {
    for (auto* p : products_)
        if (p->getName() == name) return p;
    return nullptr;
}

Product* Warehouse::findProduct(const int id) const {
    for (auto* p : products_)
        if (p->getId() == id) return p;
    return nullptr;
}

const std::vector<Product*>& Warehouse::getAll() const {
    return products_;
}

void Warehouse::printAll() const {
    std::cout << "┌─────────────────────────────────────────────────────┐\n"
              << "│              КАТАЛОГ МАГАЗИНА                       │\n"
              << "└─────────────────────────────────────────────────────┘"
              << std::endl;
    for (const auto* p : products_) {
        std::cout << "  [" << p->getCategory() << "] ";
        p->print();
    }
}
