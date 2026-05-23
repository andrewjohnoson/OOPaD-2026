// Store.h
#ifndef OOPAD_2026_STORE_H
#define OOPAD_2026_STORE_H

#include <string>
#include <memory>
#include <vector>

#include "Warehouse.h"
#include "Order.h"

class Store {
    std::string name_;
    Warehouse warehouse_;
    std::string address_;
    std::vector<std::shared_ptr<Order>> orders_;
public:
    Store();
    Store(const std::string& name, const std::string& address = "");
    ~Store();

    const std::string& getName() const;
    void setName(const std::string &);
    const std::string& getAddress() const;
    void setAddress(const std::string &);

    Warehouse& getWarehouse();
    const Warehouse& getWarehouse() const;

    void addOrder(const std::shared_ptr<Order> &);
    const std::vector<std::shared_ptr<Order>>& getOrders() const;
    std::shared_ptr<Order> findOrder(int) const;
    void confirmOrder(int);
    void cancelOrder(int);

    void addProduct(Product *);
    void showCatalog() const;
    void addToOrder(Order &, const std::string &, int);

};


#endif //OOPAD_2026_STORE_H