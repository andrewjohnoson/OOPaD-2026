// Store.cpp
#include "Store.h"

#include <iostream>
#include <iomanip>

#include "../Exceptions/OutOfStockException.h"
#include "../Exceptions/InvalidQuantityException.h"

Store::Store() : name_(""), address_("") {
    std::cout << "[CTOR] Store (default)" << std::endl;
}

Store::Store(const std::string& name, const std::string& address) : name_(name), address_(address) {
    std::cout << "[CTOR] Store: \"" << name_ << "\"" << std::endl;
}

Store::~Store() {
    std::cout << "[DTOR] Store: \"" << name_ << "\"" << std::endl;
}

const std::string& Store::getName() const {
    return name_;
}

void Store::setName(const std::string& n) {
    name_ = n;
}

const std::string& Store::getAddress() const {
    return address_;
}

void Store::setAddress(const std::string& a) {
    address_ = a;
}

Warehouse& Store::getWarehouse() {
    return warehouse_;
}

const Warehouse& Store::getWarehouse() const {
    return warehouse_;
}

void Store::addOrder(const std::shared_ptr<Order>& order) {
    orders_.push_back(order);
}

void Store::confirmOrder(const int id) {
    for (auto it = orders_.begin(); it != orders_.end(); ++it) {
        if ((*it)->getId() == id) {
            (*it)->confirm();      // печатает чек, бросает EmptyOrderException если пуст
            orders_.erase(it);     // удаляем из вектора — shared_ptr уничтожается
            return;
        }
    }
    throw std::runtime_error("Заказ с ID " + std::to_string(id) + " не найден.");
}

const std::vector<std::shared_ptr<Order>>& Store::getOrders() const {
    return orders_;
}

std::shared_ptr<Order> Store::findOrder(const int id) const {
    for (const auto& o : orders_)
        if (o->getId() == id) return o;
    return nullptr;
}

void Store::cancelOrder(const int orderId) {
    for (auto it = orders_.begin(); it != orders_.end(); ++it) {
        if ((*it)->getId() == orderId) {
            for (const auto& item : (*it)->getItems()) {
                warehouse_.findProduct(item.getProduct()->getId())
                          ->restoreStock(item.getQuantity());
            }
            orders_.erase(it);
            return;
        }
    }
    throw std::runtime_error("Заказ с ID " + std::to_string(orderId) + " не найден.");
}

void Store::addProduct(Product* p) {
    warehouse_.addProduct(p);
}

void Store::showCatalog() const {
    warehouse_.printAll();
}

void Store::addToOrder(Order& order, const std::string& productName, const int qty) {
    try {
        Product* p = warehouse_.findProduct(productName);
        if (!p)
            throw std::runtime_error("Товар \"" + productName + "\" не найден в магазине.");
        order.addItem(p, qty);
        std::cout << "  + Добавлено: " << productName
                  << " (" << qty << " шт.)" << std::endl;
    } catch (const OutOfStockException& e) {
        std::cout << "[Store] Перехвачено OutOfStock." << std::endl;
        throw;
    } catch (const InvalidQuantityException& e) {
        std::cout << "[Store] Перехвачено InvalidQuantity." << std::endl;
        throw;
    }
}