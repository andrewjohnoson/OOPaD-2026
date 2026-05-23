// Product.h
#ifndef OOPAD_2026_PRODUCT_H
#define OOPAD_2026_PRODUCT_H

#include <string>

class Product {
protected:
    int id_;
    std::string name_;
    double price_;
    int stock_;
public:
    Product() : id_(0), name_(""), price_(0.0), stock_(0) {}
    Product(int id, const std::string &, double, int);
    virtual ~Product();

    int getId() const;
    void setId(int);

    void setName(const std::string &);
    const std::string& getName() const;

    void setPrice(double);
    double getPrice() const;

    void setStock(int);
    int getStock() const;

    void reduceStock(int);
    void restoreStock(int);

    virtual void print() const;

    virtual std::string getCategory() const;
};

#endif //OOPAD_2026_PRODUCT_H