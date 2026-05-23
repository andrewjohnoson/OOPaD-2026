// OutOfStockException.h
#ifndef OOPAD_2026_OUTOFSTOCKEXCEPTION_H
#define OOPAD_2026_OUTOFSTOCKEXCEPTION_H

#include <string>

#include "StoreException.h"

class OutOfStockException : public StoreException {
    std::string itemName_;
    int requested_, available_;
public:
    OutOfStockException(const std::string& name, int requested, int available)
     : StoreException("Товар \"" + name + "\" отсутствует в нужном количестве."),
       itemName_(name), requested_(requested), available_(available) {}

    void printDetails() const;
};


#endif //OOPAD_2026_OUTOFSTOCKEXCEPTION_H