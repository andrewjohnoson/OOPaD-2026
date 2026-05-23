// Order.cpp
#include "Order.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "../Exceptions/EmptyOrderException.h"

Order::Order(const int num) : orderNumber_(num) {
    std::cout << "[CTOR] Order #" << orderNumber_ << std::endl;
}

Order::~Order() {
    std::cout << "[DTOR] Order #" << orderNumber_ << std::endl;
}

int Order::getId() const {
    return orderNumber_;
}

void Order::addItem(Product* product, const int qty) {
    product->reduceStock(qty);
    items_.emplace_back(product, qty);
}

void Order::addItemRaw(Product* product, const int qty) {
    items_.emplace_back(product, qty);
}

void Order::removeItem(const int productId, Warehouse& warehouse) {
    for (auto it = items_.begin(); it != items_.end(); ++it) {
        if (it->getProduct()->getId() == productId) {
            warehouse.findProduct(productId)->restoreStock(it->getQuantity());
            items_.erase(it);
            return;
        }
    }
    throw std::runtime_error("Товар с ID " + std::to_string(productId) +
                             " не найден в заказе.");
}

const std::vector<OrderItem>& Order::getItems() const {
    return items_;
}

double Order::total() const {
    double sum = 0;
    for (const auto& item : items_) sum += item.subtotal();
    return sum;
}

void Order::printOrderBody(const int orderNumber,
                           const std::vector<OrderItem>& items)
{
    std::cout << "┌─────────────────────────────────────────────────────┐\n"
              << "│            ЗАКАЗ #" << std::setw(3) << orderNumber
              << "                                 │\n"
              << "└─────────────────────────────────────────────────────┘"
              << std::endl;

    double total = 0;
    for (const auto& item : items) {
        const double sub = item.subtotal();
        total += sub;
        std::cout << "  [" << item.getProduct()->getId() << "] "
                  << std::left << std::setw(26) << item.getProduct()->getName()
                  << std::right << std::setw(4) << item.getQuantity() << " шт.  x "
                  << std::setw(8) << item.getProduct()->getPrice() << " = "
                  << std::setw(10) << sub << " руб." << std::endl;
    }
    std::cout << "  " << std::string(52, '-') << std::endl
              << "  ИТОГО: " << std::fixed << std::setprecision(2)
              << total << " руб." << std::endl;
}

void Order::printPreview() const {
    if (items_.empty()) {
        throw EmptyOrderException();
    }
    printOrderBody(orderNumber_, items_);
}

void Order::confirm() const {
    if (items_.empty())
        throw EmptyOrderException();
    printOrderBody(orderNumber_, items_);
    std::cout << "  Заказ оформлен." << std::endl;
}

bool Order::isEmpty() const {
    return items_.empty();
}
