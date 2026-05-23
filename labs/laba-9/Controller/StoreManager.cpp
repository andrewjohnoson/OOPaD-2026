// StoreManager.cpp
#include "StoreManager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <string>
#include <memory>
#include <stdexcept>
#include <new>

#include "../../../libs/CheckInput.h"
#include "../../../libs/TerminalController.h"
#include "OrderMenu.h"
#include "../Entities/BuildingMaterial.h"
#include "../Entities/Tool.h"

#include "../Exceptions/InvalidPriceException.h"
#include "../Exceptions/EmptyOrderException.h"
#include "../Exceptions/StoreException.h"

static const std::string STORE_FILE = "/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-9/files/store.txt";
static const std::string MATS_FILE = "/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-9/files/materials.txt";
static const std::string TOOLS_FILE = "/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-9/files/tools.txt";
static const std::string ORDERS_FILE = "/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-9/files/orders.txt";

void StoreManager::storeTerminate() {
    std::cout << "[TERMINATE] Необработанное исключение в StoreManager! "
                 "Аварийное завершение." << std::endl;
    std::abort();
}

int StoreManager::generateId() {
    std::random_device rd;
    return static_cast<int>(rd() % 90000) + 10000;
}

std::string StoreManager::inputStringSafe(const std::string& prompt) {
    std::string value;
    do {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (value.find(';') != std::string::npos)
            std::cout << "  Строка не должна содержать ';'. Повторите ввод." << std::endl;
    } while (value.find(';') != std::string::npos);
    return value;
}

void StoreManager::addBuildingMaterial(Store& store) {
    std::set_terminate(storeTerminate);

    std::cout << "Сколько стройматериалов добавить (-1 для выхода): ";
    const int n = CheckInput::inputIndex();
    if (n == -1) {
        TerminalController::waitForClick();
        return;
    }

    for (int i = 0; i < n; i++) {
        try {
            const int id = generateId();
            std::string name = inputStringSafe("Название (без ';'): ");

            std::string unit;
            while (true) {
                std::cout << "Единица измерения (кг - 1/м² - 2/шт - 3): ";
                int answer = CheckInput::inputInt();
                if (answer == 1) {
                    unit = "кг";
                    break;
                }
                if (answer == 2) {
                    unit = "м²";
                    break;
                }
                if (answer == 3) {
                    unit = "шт";
                    break;
                }

                std::cout << "Неверное значение. Повторите ввод." << std::endl;
            }

            std::cout << "Цена за единицу (руб.): ";
            const double price = CheckInput::inputDouble();
            std::cout << "Количество на складе: ";
            const int stock = CheckInput::inputInt();

            auto* mat = new BuildingMaterial(id, name, price, stock, unit);
            store.getWarehouse().addProduct(mat);
            std::cout << "Стройматериал добавлен." << std::endl;
        } catch (const InvalidPriceException& e) {
            std::cout << "[Ошибка цены] " << e.what() << std::endl
                     << "Стройматериал не добавлен. Повторите ввод." << std::endl;
            --i;
        } catch (const std::bad_alloc& e) {
            std::cout << "[Ошибка памяти] " << e.what() << std::endl
                      << "Невозможно выделить память. Добавление прервано." << std::endl;
            break;
        }
        std::cout << std::endl;
    }

    TerminalController::waitForClick();
}

void StoreManager::addTool(Store& store) {
    std::set_terminate(storeTerminate);

    std::cout << "Сколько инструментов добавить (-1 для выхода): ";
    const int n = CheckInput::inputIndex();
    if (n == -1) {
        TerminalController::waitForClick();
        return;
    }

    for (int i = 0; i < n; i++) {
        try {
            const int id = generateId();
            std::string name = inputStringSafe("Название (без ';'): ");
            std::string brand = inputStringSafe("Производитель (без ';'): ");
            std::cout << "Цена (руб.): ";
            const double price = CheckInput::inputDouble();
            std::cout << "Количество на складе: ";
            const int stock = CheckInput::inputInt();

            auto* tool = new Tool(id, name, price, stock, brand);
            store.getWarehouse().addProduct(tool);
            std::cout << "Инструмент добавлен." << std::endl;
        } catch (const InvalidPriceException& e) {
            std::cout << "[Ошибка цены] " << e.what() << std::endl;
            --i;
        } catch (const std::bad_alloc& e) {
            std::cout << "[Ошибка памяти] " << e.what() << std::endl << "Добавление прервано." << std::endl;
            break;
        }
        std::cout << std::endl;
    }

    TerminalController::waitForClick();
}

void StoreManager::createOrder(Store& store) {
    std::set_terminate(storeTerminate);

    try {
        const int id = generateId();
        const auto order = std::make_shared<Order>(id);
        store.addOrder(order);
        std::cout << "Заказ #" << id << " создан." << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cout << "[Ошибка памяти] " << e.what() << std::endl;
    }

    TerminalController::waitForClick();
}

void StoreManager::addItemToOrder(Store& store) {
    OrderMenu menu(store);
}

void StoreManager::confirmOrder(Store& store) {
    std::set_terminate(storeTerminate);

    const auto& orders = store.getOrders();
    if (orders.empty()) {
        std::cout << "Нет активных заказов." << std::endl;
        TerminalController::waitForClick();
        return;
    }

    std::cout << "ID активных заказов: ";
    for (const auto& o : orders) {
        std::cout << o->getId() << " ";
    }
    std::cout << std::endl;

    std::cout << "ID заказа (-1 для выхода): ";
    const int id = CheckInput::inputIndex();
    if (id == -1) {
        TerminalController::waitForClick();
        return;
    }

    const auto order = store.findOrder(id);
    if (order == nullptr) {
        std::cout << "Заказ не найден." << std::endl;
        TerminalController::waitForClick();
        return;
    }

    try {
        store.confirmOrder(id);
    } catch (const EmptyOrderException& e) {
        std::cout << "[Ошибка] " << e.what() << std::endl;
    } catch (const StoreException& e) {
        std::cout << "[Ошибка магазина] " << e.what() << std::endl;
    }

    TerminalController::waitForClick();
}

void StoreManager::cancelOrder(Store& store) {
    std::set_terminate(storeTerminate);

    const auto& orders = store.getOrders();
    if (orders.empty()) {
        std::cout << "Нет активных заказов." << std::endl;
        TerminalController::waitForClick();
        return;
    }

    std::cout << "ID активных заказов: ";
    for (const auto& o : orders) {
        std::cout << o->getId() << " ";
    }
    std::cout << std::endl;

    std::cout << "ID заказа для отмены (-1 для выхода): ";
    const int id = CheckInput::inputIndex();
    if (id == -1) {
        TerminalController::waitForClick();
        return;
    }

    try {
        store.cancelOrder(id);
        std::cout << "Заказ #" << id << " отменён, товары возвращены на склад." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "[Ошибка] " << e.what() << std::endl;
        TerminalController::waitForClick();
    }

    TerminalController::waitForClick();
}

void StoreManager::printCatalog(Store& store) {
    store.getWarehouse().printAll();
    TerminalController::waitForClick();
}

void StoreManager::printOrders(Store& store) {
    const auto& orders = store.getOrders();
    if (orders.empty()) {
        std::cout << "Заказов нет." << std::endl;
    } else {
        for (const auto& o : orders) {
            try {
                o->printPreview();
            } catch (const EmptyOrderException& e) {
                std::cout << "  [Заказ #" << o->getId() << " пуст]" << std::endl;
            }
        }
    }
    TerminalController::waitForClick();
}

void StoreManager::changeStoreInfo(Store& store) {
    const std::string name = inputStringSafe("Название магазина (без ';'): ");
    const std::string address = inputStringSafe("Адрес (без ';'): ");
    store.setName(name);
    store.setAddress(address);
    std::cout << "Данные обновлены." << std::endl;
    TerminalController::waitForClick();
}

void StoreManager::load(Store& store) {
    std::set_terminate(storeTerminate);

    std::ifstream storeFile(STORE_FILE);
    if (storeFile.is_open()) {
        std::string name, address;
        std::getline(storeFile, name);
        std::getline(storeFile, address);
        store.setName(name);
        store.setAddress(address);
    }

    storeFile.close();

    std::ifstream materialsFile(MATS_FILE);
    std::string line;
    while (std::getline(materialsFile, line)) {
        try {
            std::stringstream ss(line);
            std::string idStr, name, prStr, stStr, unit;
            std::getline(ss, idStr, ';');
            std::getline(ss, name,  ';');
            std::getline(ss, prStr, ';');
            std::getline(ss, stStr, ';');
            std::getline(ss, unit);

            const int id = std::stoi(idStr);
            const double price = std::stod(prStr);
            const int stock = std::stoi(stStr);

            auto* mat = new BuildingMaterial(id, name, price, stock, unit);
            store.getWarehouse().addProduct(mat);
        } catch (const InvalidPriceException& e) {
            std::cout << "[load/materials] Пропущена запись: " << e.what() << std::endl;
            TerminalController::waitForClick();
        } catch (const std::invalid_argument&) {
            std::cout << "[load/materials] Ошибка формата: " << line << std::endl;
            TerminalController::waitForClick();
        } catch (const std::bad_alloc& e) {
            std::cout << "[load/materials] Ошибка памяти: " << e.what() << std::endl;
            TerminalController::waitForClick();
            break;
        }
    }


    std::ifstream toolsFile(TOOLS_FILE);
    while (std::getline(toolsFile, line)) {
        try {
            std::stringstream ss(line);
            std::string idStr, name, prStr, stStr, brand;
            std::getline(ss, idStr, ';');
            std::getline(ss, name,  ';');
            std::getline(ss, prStr, ';');
            std::getline(ss, stStr, ';');
            std::getline(ss, brand);

            const int id = std::stoi(idStr);
            const double price = std::stod(prStr);
            const int stock = std::stoi(stStr);

            auto* tool = new Tool(id, name, price, stock, brand);
            store.getWarehouse().addProduct(tool);

        } catch (const InvalidPriceException& e) {
            std::cout << "[load/tools] Пропущена запись: " << e.what() << std::endl;
            TerminalController::waitForClick();
        } catch (const std::invalid_argument&) {
            std::cout << "[load/tools] Ошибка формата: " << line << std::endl;
            TerminalController::waitForClick();
        } catch (const std::bad_alloc& e) {
            std::cout << "[load/tools] Ошибка памяти: " << e.what() << std::endl;
            TerminalController::waitForClick();
            break;
        }
    }

    std::ifstream ordersFile(ORDERS_FILE);
    while (std::getline(ordersFile, line)) {
        try {
            std::stringstream ss(line);
            std::string idStr, countStr;
            std::getline(ss, idStr, ';');
            std::getline(ss, countStr, ';');

            const int id = std::stoi(idStr);
            const int itemCount = std::stoi(countStr);

            auto order = std::make_shared<Order>(id);

            for (int i = 0; i < itemCount; i++) {
                std::string pidStr, qtyStr;
                std::getline(ss, pidStr, ';');
                std::getline(ss, qtyStr, ';');

                const int pid = std::stoi(pidStr);
                const int qty = std::stoi(qtyStr);

                Product* p = store.getWarehouse().findProduct(pid);
                if (p == nullptr)
                    throw std::runtime_error(
                        "Товар с ID " + std::to_string(pid) + " не найден.");

                order->addItemRaw(p, qty);
            }

            store.addOrder(order);

        } catch (const std::runtime_error& e) {
            std::cout << "[load/orders] " << e.what() << std::endl;
            TerminalController::waitForClick();
        } catch (const std::invalid_argument&) {
            std::cout << "[load/orders] Ошибка формата: " << line << std::endl;
            TerminalController::waitForClick();
        }
    }
}

void StoreManager::save(Store& store) {
    {
        std::ofstream storeFile(STORE_FILE, std::ios::out);
        storeFile << store.getName() << std::endl
          << store.getAddress() << std::endl;
    }

    std::ofstream materialFile(MATS_FILE, std::ios::out);
    for (const auto* p : store.getWarehouse().getAll()) {
        if (const auto* mat = dynamic_cast<const BuildingMaterial*>(p)) {
            materialFile << mat->getId() << ";"
              << mat->getName()  << ";"
              << mat->getPrice() << ";"
              << mat->getStock() << ";"
              << mat->getUnit()  << std::endl;
        }
    }

    std::ofstream toolsFile(TOOLS_FILE, std::ios::out);
    for (const auto* p : store.getWarehouse().getAll()) {
        if (const auto* tool = dynamic_cast<const Tool*>(p)) {
            toolsFile << tool->getId() << ";"
              << tool->getName()  << ";"
              << tool->getPrice() << ";"
              << tool->getStock() << ";"
              << tool->getBrand() << std::endl;
        }
    }

    std::ofstream ordersFile(ORDERS_FILE, std::ios::out);
    for (const auto& order : store.getOrders()) {
        const auto& items = order->getItems();
        ordersFile << order->getId() << ";" << items.size() << ";";
        for (const auto& item : items) {
            ordersFile << item.getProduct()->getId() << ";"
              << item.getQuantity() << ";";
        }
        ordersFile << std::endl;
    }

    std::cout << "Данные сохранены." << std::endl;
    TerminalController::waitForClick();
}

void StoreManager::showExceptionDemo() {
    std::cout << "=== Исключение в конструкторе ===" << std::endl
              << std::endl
              << "Попытка 1: цена -500 (некорректная)." << std::endl
              << std::endl;

    try {
        BuildingMaterial bad(99999, "Тестовый материал", -500.0, 10, "кг");
    } catch (const InvalidPriceException& e) {
        std::cout << std::endl
                  << ">>> ПОЙМАНО InvalidPriceException: " << e.what() << std::endl
                  << ">>> Объект не создан, [DTOR] Product сработал автоматически." << std::endl;
    }

    std::cout << std::endl
              << "Попытка 2: цена 350 (корректная)." << std::endl
              << std::endl;

    try {
        BuildingMaterial good(88888, "Корректный материал", 350.0, 100, "кг");
        std::cout << ">>> Объект создан успешно." << std::endl
                  << std::endl
                  << "Выход из блока — деструкторы:" << std::endl;
    } catch (...) {}

    TerminalController::waitForClick();
}