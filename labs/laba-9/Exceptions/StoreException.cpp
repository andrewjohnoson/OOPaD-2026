// StoreException.cpp
#include "StoreException.h"

const char* StoreException::what() const noexcept {
    return message_.c_str();
}