// Product.cpp
#include "Product.h"

#include <iostream>
#include <iomanip>

#include "../Exceptions/InvalidPriceException.h"
#include "../Exceptions/InvalidQuantityException.h"
#include "../Exceptions/OutOfStockException.h"

Product::Product(const int id, const std::string& name, double price, int stock)
    : id_(id), name_(name), stock_(stock)
{
    std::cout << "[CTOR] Product: \"" << name << "\"" << std::endl;  ;

    if (price <= 0.0)
        throw InvalidPriceException(price);

    price_ = price;
}


Product::~Product() {
    std::cout << "[DTOR] Product: \"" << name_ << "\"" << std::endl;
}

int Product::getId() const {
    return id_;
}

void Product::setId(const int id) {
    id_ = id;
}

void Product::setName(const std::string &name) {
    name_ = name;
}

const std::string& Product::getName()  const {
    return name_;
}

void Product::setPrice(const double price) {
    if (price <= 0.0)
        throw InvalidPriceException(price);
    price_ = price;
}

double Product::getPrice() const {
    return price_;
}

void Product::setStock(const int stock) {
    stock_ = stock;
}

int Product::getStock() const {
    return stock_;
}

void Product::reduceStock(int qty) {
    if (qty <= 0)
        throw InvalidQuantityException(qty);
    if (qty > stock_)
        throw OutOfStockException(name_, qty, stock_);
    stock_ -= qty;
}

void Product::restoreStock(const int qty) {
    stock_ += qty;
}

void Product::print() const {
    std::cout << std::left << std::setw(28) << name_
              << std::right << std::setw(8) << price_ << " руб."
              << "  (остаток: " << stock_ << ")" << std::endl;
}

std::string Product::getCategory() const {
    return "Товар";
}