// EmptyOrderException.h
#ifndef OOPAD_2026_EMPTYORDEREXCEPTION_H
#define OOPAD_2026_EMPTYORDEREXCEPTION_H

#include "StoreException.h"

class EmptyOrderException : public StoreException {
public:
    EmptyOrderException() :
        StoreException("Невозможно оформить пустой заказ!") {}
};


#endif //OOPAD_2026_EMPTYORDEREXCEPTION_H