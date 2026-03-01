// ListStringController.cpp
#include "ListStringController.h"

#include "../../../../libs/CheckInput.h"
#include "../../../../libs/TerminalController.h"

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>

std::vector<LinkedListString> ListStringController::listsString;
int ListStringController::listsStringSize;

std::string ListStringController::outputFilePath = "/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-1/files/outputListString.txt";

void ListStringController::outputListsId() {
    std::cout << "ID списков: ";

    for (LinkedListString& listString : listsString) {
        std::cout << listString.getId() << " ";
    }
    std::cout << std::endl;
}

void ListStringController::createArray() {
    if (listsStringSize != 0) {
        std::cout << "Ваш массив списокв не пуст. Хотите создать новый? (0 - нет, 1 - да): ";
        do {
            int choice = CheckInput::inputInt();

            if (choice == 0) {
                return;
            }

            if (choice == 1) {
                listsString.clear();
                listsStringSize = 0;
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

    listsStringSize = n;

    TerminalController::disableInput();

    listsString.resize(listsStringSize);

    for (int i = 0; i < listsStringSize; i++) {
        listsString[i] = LinkedListString();
        listsString[i].setId(i + 1);
    }

    std::cout << "Массив создан." << std::endl;
    sleep(2);

    TerminalController::enableInput();
    TerminalController::clearTerminal();
}

void ListStringController::inputData() {
    if (listsStringSize == 0) {
        TerminalController::disableInput();
        std::cout << "Массив списков пуст." << std::endl;
        sleep(2);
        TerminalController::clearTerminal();
        TerminalController::enableInput();
        return;
    }

    outputListsId();

    do {
        std::cout << "Введите ID списка, в которой хотите ввести элементы (для выхода введите -1): ";

        const int index = CheckInput::inputIndex();

        if (index == -1) {
            std::cout << "Отмена ввода." << std::endl;
            break;
        }

        LinkedListString* requiredListString = findListStringByID(index);

        if (requiredListString == nullptr) {
            std::cout << "Списка с таким ID не существует." << std::endl;
            continue;
        }

        std::cout << "Сколько элементов хотите добавить в список: ";
        const int n = CheckInput::inputNatural();

        std::cout << "Введите элементы (в каждой строке новый элемент): ";

        std::cin.ignore();

        for (int i = 0; i < n; i++) {
            std::string x;
            std::getline(std::cin, x);
            requiredListString->pushBack(x);
        }

        std::cout << "Ввод завершён." << std::endl;
    } while (true);

    TerminalController::disableInput();
    sleep(2);
    TerminalController::enableInput();
    TerminalController::clearTerminal();
}

LinkedListString* ListStringController::findListStringByID(const int id) {
    for (LinkedListString& listString : listsString) {
        if (listString.getId() == id) {
            return &listString;
        }
    }

    return nullptr;
}

void ListStringController::sortList() {
    if (listsStringSize == 0) {
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

        LinkedListString* requiredListString = findListStringByID(index);
        if (requiredListString == nullptr) {
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

        LinkedListString::sort(requiredListString, param);

        std::cout << "Отсортировано." << std::endl;
        std::cout << std::endl;
    } while (true);

    TerminalController::disableInput();
    sleep(2);
    TerminalController::enableInput();
    TerminalController::clearTerminal();
}

void ListStringController::outputData() {
    TerminalController::disableInput();
    if (listsStringSize == 0) {
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

    for (LinkedListString& listString : listsString) {
        listString.view();

        out << "ID списка: " <<  listString.getId() << std::endl;
        out << "Элементы списка: ";

        const std::string* list = listString.getList();
        if (list == nullptr) {
            out << std::endl << std::endl;
            continue;
        }

        for (int i = 0; i < listString.getSize(); i++) {
            out << "\"" << list[i] << "\" ";
        }

        std::cout << std::endl;
        out << std::endl << std::endl;
    }

    out << "--------------------------------" << std::endl << std::endl;

    out.close();
    TerminalController::enableInput();
    std::cout << "Нажмите клавишу, чтобы продолжить." << std::endl;
    TerminalController::getch();
}

void ListStringController::addElementInList() {
    if (listsStringSize == 0) {
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

        LinkedListString* requiredListInt = findListStringByID(index);

        if (requiredListInt == nullptr) {
            std::cout << "Списка с таким ID не существует." << std::endl;
            continue;
        }

        std::cout << "Введите элемент: ";

        std::cin.ignore();

        std::string x;
        std::getline(std::cin, x);
        requiredListInt->pushBack(x);

        std::cout << "Ввод завершён." << std::endl;
    } while (true);

    TerminalController::disableInput();
    sleep(2);
    TerminalController::enableInput();
    TerminalController::clearTerminal();
}

void ListStringController::findElementInList() {
    if (listsStringSize == 0) {
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

        LinkedListString* requiredListString = findListStringByID(index);

        if (requiredListString == nullptr) {
            std::cout << "Списка с таким ID не существует." << std::endl;
            continue;
        }

        std::cout << "Введите элемент: ";

        std::cin.ignore();

        std::string x;
        std::getline(std::cin, x);
        const int pos = requiredListString->find(x);

        if (pos == -1) {
            std::cout << "Элемент не найден" << std::endl;
            sleep(2);
            TerminalController::clearTerminal();
            return;
        }

        std::cout << "Элемент " << x << " в списке с ID " << index << " находится в " << pos << "-й позиции." << std::endl;
    } while (true);

    TerminalController::disableInput();
    sleep(2);
    TerminalController::enableInput();
    TerminalController::clearTerminal();
}

void ListStringController::removeElementFromList() {
    if (listsStringSize == 0) {
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

        LinkedListString* requiredListString = findListStringByID(index);

        if (requiredListString == nullptr) {
            std::cout << "Списка с таким ID не существует." << std::endl;
            continue;
        }

        std::cout << "Введите элемент: ";

        std::cin.ignore();

        std::string x;
        std::getline(std::cin, x);
        const int pos = requiredListString->find(x);

        if (pos == -1) {
            std::cout << "Элемент не найден" << std::endl;
            sleep(2);
            TerminalController::clearTerminal();
            return;
        }

        requiredListString->removeElement(x);
        std::cout << "Выполнено." << std::endl;
    } while (true);

    TerminalController::disableInput();
    sleep(2);
    TerminalController::enableInput();
    TerminalController::clearTerminal();
}