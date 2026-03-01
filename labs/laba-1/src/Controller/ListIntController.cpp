// ListIntController.cpp
#include "ListIntController.h"

#include "../../../../libs/CheckInput.h"
#include "../../../../libs/TerminalController.h"

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>

std::vector<LinkedListInt> ListIntController::listsInt;
int ListIntController::listsIntSize;

std::string ListIntController::outputFilePath = "/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-1/files/outputListInt.txt";

void ListIntController::createArray() {
    if (listsIntSize != 0) {
        std::cout << "Ваш массив списокв не пуст. Хотите создать новый? (0 - нет, 1 - да): ";
        do {
            int choice = CheckInput::inputInt();

            if (choice == 0) {
                return;
            }

            if (choice == 1) {
                listsInt.clear();
                listsIntSize = 0;
                break;
            }

            std::cout << "Вы ввели неправильное значение." << std::endl;
        } while (true);
    }

    std::cout << "Какое количество списков Вы хотите создать (натуральное число; отмена - -1): ";
    const int n = CheckInput::inputIndex();
    if (n == -1) {
        std::cout << "Отмена ввода" << std::endl;
        sleep(1);
        return;
    }

    listsIntSize = n;

    TerminalController::disableInput();

    listsInt.resize(listsIntSize);

    for (int i = 0; i < listsIntSize; i++) {
        listsInt[i] = LinkedListInt();
        listsInt[i].setId(i + 1);
    }

    std::cout << "Массив создан." << std::endl;
    sleep(2);

    TerminalController::enableInput();
    TerminalController::clearTerminal();
}

void ListIntController::outputListsId() {
    std::cout << "ID списков: ";

    for (LinkedListInt& listInt : listsInt) {
        std::cout << listInt.getId() << " ";
    }
    std::cout << std::endl;
}

void ListIntController::inputData() {
    if (listsIntSize == 0) {
        TerminalController::disableInput();
        std::cout << "Массив списков пуст." << std::endl;
        sleep(2);
        TerminalController::clearTerminal();
        TerminalController::enableInput();
        return;
    }

    outputListsId();

    do {
        std::cout << "Введите ID списка, в который хотите ввести элементы (для выхода введите -1): ";

        const int index = CheckInput::inputIndex();

        if (index == -1) {
            std::cout << "Отмена ввода." << std::endl;
            break;
        }

        LinkedListInt* requiredListInt = findListIntByID(index);

        if (requiredListInt == nullptr) {
            std::cout << "Списка с таким ID не существует." << std::endl;
            continue;
        }

        std::cout << "Сколько элементов хотите добавить в список: ";
        const int n = CheckInput::inputNatural();

        std::cout << "Введите элементы (в каждой строке новый элемент): ";

        for (int i = 0; i < n; i++) {
            const int x = CheckInput::inputInt();
            requiredListInt->pushBack(x);
        }

        std::cout << "Ввод завершён." << std::endl;
    } while (true);

    TerminalController::disableInput();
    sleep(2);
    TerminalController::enableInput();
    TerminalController::clearTerminal();
}

LinkedListInt* ListIntController::findListIntByID(const int id) {
    for (LinkedListInt& listInt : listsInt) {
        if (listInt.getId() == id) {
            return &listInt;
        }
    }

    return nullptr;
}

void ListIntController::sortList() {
    if (listsIntSize == 0) {
        TerminalController::disableInput();
        std::cout << "Массив списков пуст." << std::endl;
        sleep(1);
        TerminalController::clearTerminal();
        TerminalController::enableInput();
        return;
    }

    outputListsId();

    do {
        std::cout << "Введите ID списка, который хотите сортировать (для выхода введите -1): ";
        const int index = CheckInput::inputIndex();

        if (index == -1) {
            std::cout << "Отмена ввода." << std::endl;
            break;
        }

        LinkedListInt* requiredListInt = findListIntByID(index);
        if (requiredListInt == nullptr) {
            std::cout << "Списка с таким ID не существует." << std::endl;
            continue;
        }

        std::cout << "Как хотите отсортировать список (0 - в порядке возрастания, 1 - в порядке убывания): ";
        int param;
        do {
            const int choice = CheckInput::inputInt();
            if (choice == 0) {
                param = 0;
                break;
            }
            if (choice == 1) {
                param = 1;
                break;
            }

            std::cout << "Неправильное значение." << std::endl;
        } while (true);

        LinkedListInt::sort(requiredListInt, param);

        std::cout << "Отсортировано." << std::endl;
        std::cout << std::endl;
    } while (true);

    TerminalController::disableInput();
    sleep(2);
    TerminalController::enableInput();
    TerminalController::clearTerminal();
}

void ListIntController::outputData() {
    TerminalController::disableInput();
    if (listsIntSize == 0) {
        std::cout << "Массив списков пуст." << std::endl;
        sleep(2);
        TerminalController::clearTerminal();
        TerminalController::enableInput();
        return;
    }

    std::ofstream out(outputFilePath, std::ios::app);

    if (!out.is_open()) {
        std::cout << "Не удалось открыть файл. Вывод данных невозможен." << std::endl;

        sleep(2);
        return;
    }

    for (LinkedListInt& listInt : listsInt) {
        listInt.view();

        out << "ID списка: " <<  listInt.getId() << std::endl;
        out << "Элементы списка: ";

        const int* list = listInt.getList();

        if (list == nullptr) {
            out << std::endl << std::endl;
            continue;
        }

        for (int i = 0; i < listInt.getSize(); i++) {
            out << list[i] << " ";
        }

        std::cout << std::endl << std::endl;
        out << std::endl << std::endl;
    }

    out << "--------------------------------" << std::endl << std::endl;

    out.close();
    TerminalController::enableInput();
    std::cout << "Нажмите клавишу, чтобы продолжить." << std::endl;
    TerminalController::getch();
}

void ListIntController::addElementInList() {
    if (listsIntSize == 0) {
        TerminalController::disableInput();
        std::cout << "Массив списков пуст." << std::endl;
        sleep(2);
        TerminalController::clearTerminal();
        TerminalController::enableInput();
        return;
    }

    outputListsId();

    do {
        std::cout << "Введите ID списка, в который хотите добавить элемент (для выхода введите -1): ";

        const int index = CheckInput::inputIndex();

        if (index == -1) {
            std::cout << "Отмена ввода." << std::endl;
            break;
        }

        LinkedListInt* requiredListInt = findListIntByID(index);

        if (requiredListInt == nullptr) {
            std::cout << "Списка с таким ID не существует." << std::endl;
            continue;
        }

        std::cout << "Введите элемент: ";

        const int x = CheckInput::inputInt();
        requiredListInt->pushBack(x);

        std::cout << std::endl;

        std::cout << "Ввод завершён." << std::flush;
    } while (true);

    TerminalController::disableInput();
    sleep(2);
    TerminalController::enableInput();
    TerminalController::clearTerminal();
}

void ListIntController::findElementInList() {
    if (listsIntSize == 0) {
        TerminalController::disableInput();
        std::cout << "Массив списков пуст." << std::endl;
        sleep(2);
        TerminalController::clearTerminal();
        TerminalController::enableInput();
        return;
    }

    outputListsId();

    do {
        std::cout << "Введите ID списка, в котором хотите найти элемент (для выхода введите -1): ";

        const int index = CheckInput::inputIndex();

        if (index == -1) {
            std::cout << "Отмена ввода." << std::endl;
            break;
        }

        LinkedListInt* requiredListInt = findListIntByID(index);

        if (requiredListInt == nullptr) {
            std::cout << "Списка с таким ID не существует." << std::endl;
            continue;
        }

        std::cout << "Введите элемент: ";

        const int x = CheckInput::inputInt();
        const int pos = requiredListInt->find(x);

        if (pos == -1) {
            std::cout << "Элемент не найден" << std::endl;
            sleep(2);
            TerminalController::clearTerminal();
            return;
        }

        std::cout << "Элемент " << x << " в списке с ID " << index << " находится в " << pos << "-й позиции." << std::endl;
        std::cout << "Нажмите клавишу, чтобы продолжить." << std::endl;
        TerminalController::getch();
    } while (true);

    TerminalController::disableInput();
    sleep(2);
    TerminalController::enableInput();
    TerminalController::clearTerminal();
}

void ListIntController::removeElementFromList() {
    if (listsIntSize == 0) {
        TerminalController::disableInput();
        std::cout << "Массив списков пуст." << std::endl;
        sleep(2);
        TerminalController::clearTerminal();
        TerminalController::enableInput();
        return;
    }

    outputListsId();

    do {
        std::cout << "Введите ID списка, из которого хотите удалить элемент (для выхода введите -1): ";

        const int index = CheckInput::inputIndex();

        if (index == -1) {
            std::cout << "Отмена ввода." << std::endl;
            break;
        }

        LinkedListInt* requiredListInt = findListIntByID(index);

        if (requiredListInt == nullptr) {
            std::cout << "Списка с таким ID не существует." << std::endl;
            continue;
        }

        std::cout << "Введите элемент: ";

        const int x = CheckInput::inputInt();
        const int pos = requiredListInt->find(x);

        if (pos == -1) {
            std::cout << "Элемент не найден" << std::endl;
            sleep(2);
            TerminalController::clearTerminal();
            return;
        }

        requiredListInt->removeElement(x);
        std::cout << "Выполнено." << std::endl;
    } while (true);

    TerminalController::disableInput();
    sleep(2);
    TerminalController::enableInput();
    TerminalController::clearTerminal();
}