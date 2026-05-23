// StoreException.h
#ifndef OOPAD_2026_STOREEXCEPTION_H
#define OOPAD_2026_STOREEXCEPTION_H

#include <string>

class StoreException : public std::exception {
    std::string message_;
public:
    StoreException(const std::string& msg) : message_(msg) {}
    const char* what() const noexcept override;
};


#endif //OOPAD_2026_STOREEXCEPTION_H