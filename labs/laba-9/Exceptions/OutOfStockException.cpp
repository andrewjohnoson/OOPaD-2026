// OutOfStockException.cpp
#include "OutOfStockException.h"

#include <iostream>

void OutOfStockException::printDetails() const {
    std::cout << "  Товар    : " << itemName_ << std::endl
              << "  Запрошено: " << requested_ << " шт." << std::endl
              << "  В наличии: " << available_ << " шт." << std::endl;
}
