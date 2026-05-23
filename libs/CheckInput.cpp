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
        std::cin.ignore();
    }


    return x;
}

int CheckInput::inputIndex() {
    int x;

    while (!(std::cin >> x) || std::cin.peek() != '\n' || x < 1) {
        if (x == -1) {
            return x;
        };

        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
        std::cout << "Ошибка ввода. Введите число n > 0 или -1 для выхода: ";
    }

    std::cin.ignore();

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

    std::cin.ignore();

    return x;
}

double CheckInput::inputDouble() {
    double x;

    while (!(std::cin >> x) || std::cin.peek() != '\n') {
        std::cout << "Ошибка ввода." << std::endl;

        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }

    std::cin.ignore();

    return x;
}

unsigned CheckInput::inputUnsigned() {
    unsigned x;

    while (!(std::cin >> x) || std::cin.peek() != '\n') {
        std::cout << "Ошибка ввода." << std::endl;

        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }

    std::cin.ignore();

    return x;
}

unsigned CheckInput::inputYear() {
    unsigned y;

    while (!(std::cin >> y) || std::cin.peek() != '\n' || y < 2000 || y > 2500) {
        std::cout << "Год от 2000 до 2500. Повторите ввод: ";

        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }

    std::cin.ignore();

    return y;
}

unsigned CheckInput::inputMonth() {
    unsigned m;

    while (!(std::cin >> m) || std::cin.peek() != '\n' || m < 1 || m > 12) {
        std::cout << "Месяцев всего двенадцать. Повторите ввод: ";

        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }

    std::cin.ignore();

    return m;
}

unsigned CheckInput::inputDay(const unsigned year, const unsigned month) {
    unsigned d;
    bool correct = false;
    while (!correct) {
        while (!(std::cin >> d) || std::cin.peek() != '\n' || d < 1 || d > 31) {
            std::cout << "Неверное значение. Повторите ввод: ";

            std::cin.clear();
            while (std::cin.peek() != '\n') {
                std::cin.ignore();
            }
        }

        correct = true;

        if (month == 2) {
            const bool leapYear = isLeapYear(year);
            if (leapYear && d > 29) {
                std::cout << "В високосном году в феврале 29 дней. Повторите ввод: ";
                correct = false;
            }
            if (!leapYear && d > 28) {
                std::cout << "В феврале 28 дней. Повторите ввод: ";
                correct = false;
            }
        }

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (d > 31) {
                std::cout << "Не более 31 дня. Повторите ввод: ";
                correct = false;
            }
        } else {
            if (d > 30) {
                std::cout << "Не более 30 дней. Повторите ввод: ";
                correct = false;
            }
        }
    }

    std::cin.ignore();

    return d;
}

bool CheckInput::isLeapYear(unsigned year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    return false;
}

unsigned CheckInput::inputHour() {
    unsigned h;

    while (!(std::cin >> h) || std::cin.peek() != '\n' || h > 23) {
        std::cout << "Число от 0 до 23. Повторите ввод: ";

        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }

    std::cin.ignore();

    return h;
}

unsigned CheckInput::inputMinute() {
    unsigned mt;

    while (!(std::cin >> mt) || std::cin.peek() != '\n' || mt > 59) {
        std::cout << "Минуты от 0 до 59. Повторите ввод: ";

        std::cin.clear();
        while (std::cin.peek() != '\n') {
            std::cin.ignore();
        }
    }

    std::cin.ignore();

    return mt;
}