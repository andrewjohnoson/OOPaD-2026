// TransactionMenu.cpp
#include "TransactionMenu.h"

#include "../../../libs/TerminalController.h"
#include "../../../libs/CheckInput.h"

#include <string>

TransactionMenu::TransactionMenu(Library &lib) : lib(lib), activeSubscription(nullptr) {
    std::cout << "Список ID абониментов: " << std::endl;
    for (const auto &s : lib.getSubscriptions().getAll()) {
        std::cout << s->getId() << " ";
    }

    std::cout << std::endl;

    while (true) {
        std::cout << "ID абонемента (-1 для выхода): ";
        const int subId = CheckInput::inputIndex();

        if (subId == -1) {
            TerminalController::waitForClick();
            return;
        }

        activeSubscription = lib.findSubscription(subId);

        if (activeSubscription == nullptr) {
            std::cout << "Абонемент не найден." << std::endl;
        } else {
            break;
        }
    }

    if (!activeSubscription->isEditable()) {
        std::cout << "Сотрудник работает с данным абонементом. Изменения невозможны." << std::endl;
        TerminalController::waitForClick();
        return;
    }

    activeSubscription->beginTransaction();
    std::cout << "Пока транзакция не подтверждена изменения можно отменить." << std::endl
     << "При выходе из меню все изменению отменяются." << std::endl;
    TerminalController::waitForClick();

    isActive = true;
    Menu::init({
        "Добавить книги в абонемент", "Показать изменения в транзакции", "Подтвердить транзакцию", "Отменить транзакцию"
    },
    "Управление абонементом [" + std::to_string(activeSubscription->getId()) + "]");
}

void TransactionMenu::showMenu() {
    while (isActive) {
        std::cout << this->menuTitle << std::endl << "================================" << std::endl << std::endl;
        for (int i = 1; i <= this->menuCounter; i++) {
            if (i == this->selected) {
                std::cout << "--> " << "\033[7m" << i << ". " << this->menuPoints[i - 1] << "\033[0m" << std::endl;
                continue;
            }
            std::cout << "    " << i << ". " << this->menuPoints[i - 1] << std::endl;
        }

        if (this->selected == this->menuCounter + 1) {
            std::cout << "--> " << "\033[7m" << this->menuCounter + 1 << ". Выйти из приложения." << "\033[0m" << std::endl;
        } else {
            std::cout << "    " << this->menuCounter + 1 << ". Выйти из приложения." << std::endl;
        }

        const int button = this->getButton();

        if (button == this->DOWN_ARROW_BUTTON) {
            this->selected++;
            if (this->selected > this->menuCounter + 1) {
                this->selected = 1;
            }

            TerminalController::clearTerminal();
        }

        if (button == this->UP_ARROW_BUTTON) {
            selected--;
            if (selected < 1) {
                this->selected = this->menuCounter + 1;
            }

            TerminalController::clearTerminal();
        }

        if (button == this->ENTER_BUTTON) {
            TerminalController::clearTerminal();

            this->doMenuAction(this->selected);
            TerminalController::clearTerminal();
        }
        TerminalController::clearTerminal();
    }
}

void TransactionMenu::doMenuAction(const int selected) {
    if (selected == menuCounter + 1) {
        if (activeSubscription && activeSubscription->hasActiveTransaction()) {
            activeSubscription->rollback();
        }

        isActive = false;
        return;
    }

    if (selected == ADD_BOOK) {
        if (!activeSubscription->hasActiveTransaction()) {
            activeSubscription->beginTransaction();
        }

        std::cout << "Список ID книг: " << std::endl;
        for (const auto &b : lib.getBooks().getAll()) {
            std::cout << b->getId() << " ";
        }

        std::cout << std::endl;

        std::shared_ptr<Book> b;

        while (true) {
            std::cout << "ID абонемента (-1 для выхода): ";
            const int bookId = CheckInput::inputIndex();

            if (bookId == -1) {
                TerminalController::waitForClick();
                return;
            }

            b = lib.findBook(bookId);

            if (b == nullptr) {
                std::cout << "Книга не найдена." << std::endl;
            } else {
                break;
            }
        }

        activeSubscription->addBook(b);

        std::cout<<"Книга добавлена в абонимент." << std::endl;
        TerminalController::waitForClick();
    }

    if (selected == SHOW) {
        if (!activeSubscription->hasActiveTransaction()) {
            activeSubscription->beginTransaction();
        }

        activeSubscription->print();
        TerminalController::waitForClick();
        std::cout << std::endl;
    }

    if (selected == COMMIT) {
        if (!activeSubscription->hasActiveTransaction()) {
            std::cout << "Нет активной транзакции для подтверждения." << std::endl;
            TerminalController::waitForClick();
            return;
        }
        activeSubscription->commit();
        std::cout << "Изменения зафиксированы." << std::endl;
        TerminalController::waitForClick();
    }

    if (selected == ROLLBACK) {
        if (!activeSubscription->hasActiveTransaction()) {
            std::cout << "  Нет активной транзакции для отмены.\n";
            TerminalController::waitForClick();
            return;
        }

        activeSubscription->rollback();
        TerminalController::waitForClick();
    }
}