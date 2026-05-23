// Warehouse.h
#ifndef OOPAD_2026_WAREHOUSE_H
#define OOPAD_2026_WAREHOUSE_H

#include <vector>

#include "Product.h"

class Warehouse {
    std::vector<Product*> products_;
public:
    void addProduct(Product* p);
    Product* findProduct(const std::string& name) const;
    Product* findProduct(int) const;

    const std::vector<Product*>& getAll() const;

    void printAll() const;
};


#endif //OOPAD_2026_WAREHOUSE_H