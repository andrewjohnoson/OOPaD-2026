// OrderMenu.cpp
#include "OrderMenu.h"

#include <iostream>
#include <stdexcept>

#include "../../../libs/CheckInput.h"
#include "../../../libs/TerminalController.h"

#include "../Exceptions/OutOfStockException.h"
#include "../Exceptions/InvalidQuantityException.h"
#include "../Exceptions/EmptyOrderException.h"
#include "../Exceptions/StoreException.h"

OrderMenu::OrderMenu(Store& store) : store_(store) {
    isActive = true;
    init(
        {
            "Выбрать заказ",
            "Добавить товар в заказ",
            "Удалить товар из заказа",
            "Просмотреть текущий заказ"
        },
        "Управление заказом"
    );
}

void OrderMenu::showMenu() {
    while (isActive) {
        std::cout << menuTitle << std::endl
                  << "================================" << std::endl << std::endl;

        for (int i = 1; i <= menuCounter; i++) {
            if (i == selected)
                std::cout << "--> \033[7m" << i << ". " << menuPoints[i - 1] << "\033[0m" << std::endl;
            else
                std::cout << "    " << i << ". " << menuPoints[i - 1] << std::endl;
        }

        if (selected == menuCounter + 1)
            std::cout << "--> \033[7m" << menuCounter + 1 << ". Вернуться в главное меню.\033[0m" << std::endl;
        else
            std::cout << "    " << menuCounter + 1 << ". Вернуться в главное меню." << std::endl;

        const int button = getButton();

        if (button == DOWN_ARROW_BUTTON) {
            selected++;
            if (selected > menuCounter + 1) selected = 1;
            TerminalController::clearTerminal();
        }

        if (button == UP_ARROW_BUTTON) {
            selected--;
            if (selected < 1) selected = menuCounter + 1;
            TerminalController::clearTerminal();
        }

        if (button == ENTER_BUTTON) {
            TerminalController::clearTerminal();
            doMenuAction(selected);
            TerminalController::clearTerminal();
        }

        TerminalController::clearTerminal();
    }
}

void OrderMenu::doMenuAction(const int selected) {
    if (selected == menuCounter + 1) {
        isActive = false;
        return;
    }

    if (selected == SELECT_ORDER)  selectOrder();
    if (selected == ADD_PRODUCT)   addProduct();
    if (selected == REMOVE_PRODUCT) removeProduct();
    if (selected == SHOW_ORDER)    showOrder();
}

void OrderMenu::selectOrder() {
    const auto& orders = store_.getOrders();
    if (orders.empty()) {
        std::cout << "Нет активных заказов. Сначала создайте заказ." << std::endl;
        TerminalController::waitForClick();
        return;
    }

    std::cout << "ID активных заказов: ";
    for (const auto& o : orders) std::cout << o->getId() << " ";
    std::cout << std::endl;

    while (true) {
        std::cout << "ID заказа (-1 для выхода): ";
        const int id = CheckInput::inputIndex();
        if (id == -1) {
            TerminalController::waitForClick();
            return;
        }

        auto found = store_.findOrder(id);
        if (found == nullptr) {
            std::cout << "Заказ не найден." << std::endl;
        } else {
            currentOrder_ = found;
            std::cout << "Выбран заказ #" << id << "." << std::endl;
            break;
        }
    }

    TerminalController::waitForClick();
}

void OrderMenu::addProduct() {
    if (currentOrder_ == nullptr) {
        std::cout << "Сначала выберите заказ (пункт 1)." << std::endl;
        TerminalController::waitForClick();
        return;
    }

    store_.getWarehouse().printAll();

    std::cout << "ID товара (-1 для выхода): ";
    const int productId = CheckInput::inputIndex();
    if (productId == -1) {
        TerminalController::waitForClick();
        return;
    }

    Product* product = store_.getWarehouse().findProduct(productId);
    if (product == nullptr) {
        std::cout << "Товар не найден." << std::endl;
        TerminalController::waitForClick();
        return;
    }

    std::cout << "Количество: ";
    const int qty = CheckInput::inputInt();

    try {
        currentOrder_->addItem(product, qty);
        std::cout << "Добавлено: " << product->getName() << " x " << qty << " шт." << std::endl;

    } catch (const OutOfStockException& e) {
        std::cout << "[Нет на складе] " << e.what() << std::endl;
        e.printDetails();
    } catch (const InvalidQuantityException& e) {
        std::cout << "[Некорректное количество] " << e.what() << std::endl;

    } catch (const StoreException& e) {
        std::cout << "[Ошибка] " << e.what() << std::endl;
    }

    TerminalController::waitForClick();
}

void OrderMenu::removeProduct() {
    if (currentOrder_ == nullptr) {
        std::cout << "Сначала выберите заказ (пункт 1)." << std::endl;
        TerminalController::waitForClick();
        return;
    }

    const auto& items = currentOrder_->getItems();
    if (items.empty()) {
        std::cout << "Заказ пуст." << std::endl;
        TerminalController::waitForClick();
        return;
    }

    std::cout << "Товары в заказе:" << std::endl;
    for (const auto& item : items) {
        std::cout << "  [" << item.getProduct()->getId() << "] "
                  << item.getProduct()->getName()
                  << " x " << item.getQuantity() << " шт." << std::endl;
    }

    std::cout << "ID товара для удаления (-1 для выхода): ";
    const int productId = CheckInput::inputIndex();
    if (productId == -1) {
        TerminalController::waitForClick();
        return;
    }

    try {
        currentOrder_->removeItem(productId, store_.getWarehouse());
        std::cout << "Товар удалён из заказа, остаток возвращён на склад." << std::endl;

    } catch (const std::runtime_error& e) {
        std::cout << "[Ошибка] " << e.what() << std::endl;
    }

    TerminalController::waitForClick();
}

void OrderMenu::showOrder() const {
    if (currentOrder_ == nullptr) {
        std::cout << "Заказ не выбран." << std::endl;
    } else {
        try {
            currentOrder_->printPreview();
        } catch (const EmptyOrderException& e) {
            std::cout << "[Пустой заказ] " << e.what() << std::endl;
        }
    }
    TerminalController::waitForClick();
}