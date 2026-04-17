#include "ThirdLabMenu.h"

#include "../../../../libs/TerminalController.h"

void ThirdLabMenu::doMenuAction(const int selected) {
    if (selected == this->menuCounter + 1) {
        std::cout << "Выход." << std::endl;
        exit(0);
    }

    if (selected == INPUT_FIRST_DISTANCE) {
        std::cout << "Введите первую дистанцию." << std::endl;
        std::cin >> d1;
        std::cout << "Введено. Нажмите клавишу, чтобы продолжить." << std::endl;
        TerminalController::getch();
    }

    if (selected == INPUT_SECOND_DISTANCE) {
        std::cout << "Введите вторую дистанцию." << std::endl;
        std::cin >> d2;
        std::cout << "Введено. Нажмите клавишу, чтобы продолжить." << std::endl;
        TerminalController::getch();
    }

    if (selected == SUM_DISTANCES) {
        std::cout << "Сумма дистанций = " << std::endl;
        std::cout << d1 + d2 << std::endl;
        std::cout << "Нажмите клавишу, чтобы продолжить." << std::endl;
        TerminalController::getch();
    }

    if (selected == DIFFERENCE_DISTANCE) {
        std::cout << "Разница дистанций = " << std::endl;
        std::cout << d1 - d2 << std::endl;
        std::cout << "Нажмите клавишу, чтобы продолжить." << std::endl;
        TerminalController::getch();
    }

    if (selected == CHECK_EQUALITY) {
        if (d1 == d2) {
            std::cout << "Дистацнии равны." << std::endl;
        } else {
            std::cout << "Дистанции не равны." << std::endl;
        }
        std::cout << "Нажмите клавишу, чтобы продолжить." << std::endl;
        TerminalController::getch();
    }

    if (selected == OUTPUT_DISTANCES) {
        std::cout << "Дистацния №1." << std::endl;
        std::cout << d1 << std::endl;

        std::cout << "Дистацния №2." << std::endl;
        std::cout << d2 << std::endl;

        std::cout << "Нажмите клавишу, чтобы продолжить." << std::endl;
        TerminalController::getch();
    }
}
