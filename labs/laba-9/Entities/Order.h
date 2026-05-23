// Order.h
#ifndef OOPAD_2026_ORDER_H
#define OOPAD_2026_ORDER_H

#include <vector>

#include "OrderItem.h"
#include "Warehouse.h"

class Order {
    std::vector<OrderItem> items_;
    int orderNumber_;
public:
    Order() : orderNumber_(0) {}
    Order(int);
    ~Order();

    int getId() const;
    void addItem(Product* product, int qty);
    void addItemRaw(Product* product, int qty);
    void removeItem(int productId, Warehouse& warehouse);
    const std::vector<OrderItem>& getItems() const;
    double total() const;
    static void printOrderBody(int, const std::vector<OrderItem> &);
    void printPreview() const;
    void confirm() const;
    bool isEmpty() const;

};


#endif //OOPAD_2026_ORDER_H