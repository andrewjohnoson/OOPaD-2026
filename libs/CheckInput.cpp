// CheckInput.cpp
#include "CheckInput.h"

#include <iostream>

int CheckInput::inputNatural() {
    int x;

    while (!(std::cin >> x) || std::cin.peek() != '\n' || x < 1) {
        std::cout << "Ошибка ввода. Необходимо ввести число n > 0" << std::endl;

        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }

    return x;
}

int CheckInput::inputIndex() {
    int x;

    while (!(std::cin >> x) || std::cin.peek() != '\n' || x < 1) {
        if (x == -1) {
            break;
        }

        std::cout << "Ошибка ввода. Необходимо ввести число n > 0" << std::endl;

        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }

    return x;
}

int CheckInput::inputInt() {
    int x;

    while (!(std::cin >> x) || std::cin.peek() != '\n') {
        std::cout << "Ошибка ввода." << std::endl;

        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }

    return x;
}