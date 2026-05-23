// OrderItem.cpp
#include "OrderItem.h"

void OrderItem::setQuantity(int q) {
    quantity_ = q;
}

void OrderItem::setProduct(Product* p) {
    product_ = p;
}

Product* OrderItem::getProduct() const {
    return product_;
}

int OrderItem::getQuantity() const {
    return quantity_;
}

double OrderItem::subtotal() const{
    return product_->getPrice() * quantity_;
}