// OrderItem.h
#ifndef OOPAD_2026_ORDERITEM_H
#define OOPAD_2026_ORDERITEM_H

#include "Product.h"

class OrderItem {
    Product* product_;
    int quantity_;
public:
    OrderItem() : product_(nullptr), quantity_(0) {}
    OrderItem(Product* product, const int quantity) : product_(product), quantity_(quantity) {}

    void setProduct(Product *);
    void setQuantity(int);

    Product* getProduct() const;
    int getQuantity() const;

    double subtotal() const;
};


#endif //OOPAD_2026_ORDERITEM_H