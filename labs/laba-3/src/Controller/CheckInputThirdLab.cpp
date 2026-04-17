#include "CheckInputThirdLab.h"

unsigned CheckInput::inputNatural(std::istream &is) {
    unsigned x;
    while (!(is >> x) || is.peek() != '\n') {
        std::cout << "Введённое число должно быть целым положительным." << std::endl;
        is.clear();
        while (is.peek() != '\n') {
            is.ignore();
        }
    }

    is.ignore();
    return x;
}
