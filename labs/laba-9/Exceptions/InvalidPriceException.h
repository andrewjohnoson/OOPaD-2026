// InvalidPriceException.h
#ifndef OOPAD_2026_INVALIDPRICEEXCEPTION_H
#define OOPAD_2026_INVALIDPRICEEXCEPTION_H

#include "StoreException.h"

class InvalidPriceException : public StoreException {
public:
    InvalidPriceException(double price)
        : StoreException("Некорректная цена: " + std::to_string(price) +
                         ". Цена должна быть положительной.") {}

};


#endif //OOPAD_2026_INVALIDPRICEEXCEPTION_H