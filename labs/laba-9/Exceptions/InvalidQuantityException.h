// InvalidQuantityException.h
#ifndef OOPAD_2026_INVALIDQUANTITYEXCEPTION_H
#define OOPAD_2026_INVALIDQUANTITYEXCEPTION_H

#include "StoreException.h"

class InvalidQuantityException : public StoreException {
public:
    InvalidQuantityException(const int qty)
    : StoreException("Некорректное количество: " + std::to_string(qty) +
                     ". Должно быть > 0.") {}

};


#endif //OOPAD_2026_INVALIDQUANTITYEXCEPTION_H