// Transaction.h
#ifndef OOPAD_2026_TRANSACTION_H
#define OOPAD_2026_TRANSACTION_H

#include <memory>
#include <iostream>

template <class T>
class Transaction {
    std::shared_ptr<T> prevState;
    std::shared_ptr<T> currentState;
public:
    Transaction()
    : prevState(nullptr), currentState(std::make_shared<T>()) {}

    Transaction(const T& obj)
        : currentState(std::make_shared<T>(obj)),
          prevState(nullptr) {}

    Transaction(const Transaction &t) :
        currentState(std::make_shared<T>(*t.currentState)),
        prevState(nullptr) {}
    ~Transaction();

    Transaction& operator= (const Transaction &t);
    void beginTransaction();
    void commit();
    void deleteTransaction();
    T* operator->() const;
    T& get();
    bool hasActiveTransaction();
};

template<class T>
Transaction<T>::~Transaction() {
    if (hasActiveTransaction()) {
        deleteTransaction();
    }
}

template<class T>
Transaction<T>& Transaction<T>::operator=(const Transaction &t) {
    if (this != &t) {
        currentState = std::make_shared<T>(*t.currentState);
    }
    return *this;
}

template <class T>
T* Transaction<T>::operator->() const {
    return currentState->get();
}

template <class T>
void Transaction<T>::beginTransaction() {
    if (prevState != nullptr) {
        std::cout << "[Транзакция] Транзакция уже происходит." << std::endl;
        return;
    }

    prevState = std::make_shared<T>(*currentState);
    std::cout << "[Транзакция] Транзакция запущена." << std::endl;
}

template <class T>
void Transaction<T>::commit() {
    if (prevState == nullptr) {
        std::cout << "[Транзакция] Транзакция не активна." << std::endl;
    }

    prevState = nullptr;
    std::cout << "[Транзакция] Транзакция произведена" << std::endl;
}

template <class T>
void Transaction<T>::deleteTransaction() {
    if (prevState == nullptr) {
        std::cout << "[Транзакция] Нет активной транзакции для отката." << std::endl;
        return;
    }

    std::cout << "[Транзакция] Транзакция отменена" << std::endl;

    currentState = prevState;
    prevState = nullptr;
}

template<class T>
bool Transaction<T>::hasActiveTransaction() {
    return prevState != nullptr;
}

template<class T>
T& Transaction<T>::get() {
    return *currentState;
}

#endif //OOPAD_2026_TRANSACTION_H