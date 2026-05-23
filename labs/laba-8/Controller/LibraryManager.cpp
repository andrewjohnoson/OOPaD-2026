// LibraryManager.cpp
#include "LibraryManager.h"

#include <random>
#include <string>
#include <fstream>
#include <sstream>

#include "../../../libs/CheckInput.h"
#include "../../../libs/TerminalController.h"
#include "TransactionMenu.h"

void LibraryManager::addBook(Library &lib) {
    std::cout << "Сколько кинг хотите добавить (-1 для выхода): ";
    const int n = CheckInput::inputIndex();

    if (n == -1) {
        TerminalController::waitForClick();
        return;
    }

    for (int i = 0; i < n; i++) {
        std::random_device rd;
        int id = rd() % 10000;
        std::string title, author;

        do {
            std::cout << "Введите название (не должно содержать ;): ";
            std::getline(std::cin, title);
        } while (title.find(';') != std::string::npos);

        do {
            std::cout << "Автор (не должно содержать ;): ";
            std::getline(std::cin, author);
        } while (author.find(';') != std::string::npos);

        std::cout << "Год: ";
        const int year = CheckInput::inputYear();

        std::cout << "Количество: ";
        const int copies = CheckInput::inputInt();

        std::cout << std::endl;

        lib.addBook(std::make_shared<Book>(Book(id, title, author, year, copies)));
    }

    std::cout << "Книга добавлена." << std::endl;
    TerminalController::waitForClick();
}

void LibraryManager::addReader(Library &lib) {
    std::cout << "Сколько читателей хотите добавить (-1 для выхода): ";
    const int n = CheckInput::inputIndex();

    if (n == -1) {
        return;
    }

    for (int i = 0; i < n; i++) {
        std::random_device rd;
        const int id = rd() % 10000;
        std::string name;

        do {
            std::cout << "Введите имя (не должно содержать ;): ";
            std::getline(std::cin, name);
        } while (name.find(';') != std::string::npos);
        std::cout << std::endl;
        lib.addReader(std::make_shared<Reader>(Reader(id, name)));
    }

    std::cout << "Читатель добавлен." << std::endl;
    TerminalController::waitForClick();
}

void LibraryManager::addEmployee(Library &lib) {
    std::cout << "Сколько сотрудников хотите добавить (-1 для выхода): ";
    const int n = CheckInput::inputIndex();

    if (n == -1) {
        return;
    }

    for (int i = 0; i < n; i++) {
        std::random_device rd;
        const int id = rd() % 10000;
        std::string name, pos;

        do {
            std::cout << "Введите имя (не должно содержать ;): ";
            std::getline(std::cin, name);
        } while (name.find(';') != std::string::npos);

        do {
            std::cout << "Введите должность (не должно содержать ;): ";
            std::getline(std::cin, pos);
        } while (pos.find(';') != std::string::npos);

        std::cout << std::endl;
        lib.addEmployee(std::make_shared<Employee>(Employee(id, name, pos)));
    }

    std::cout << "Сотрудник добавлен." << std::endl;
    TerminalController::waitForClick();
}

void LibraryManager::createSubscription(Library &lib) {
    std::random_device rd;
    const int subId = rd() % 10000;

    std::cout << "Список ID читателей: " << std::endl;
    for (const auto &reader : lib.getReaders().getAll()) {
        std::cout << reader->getId() << " ";
    }

    std::cout << std::endl;

    std::cout << "ID читателя: ";
    const int readerId = CheckInput::inputInt();

    auto r = lib.findReader(readerId);

    if (r == nullptr) {
        std::cout << "Читатель не найден." << std::endl;
        return;
    }

    if (lib.findSubscriptionByUser(readerId) == nullptr) {
        auto s = std::make_shared<Subscription>(Subscription(subId, r));
        lib.addSubscription(s);
        std::cout << "Абонимент создан." << std::endl;
    } else {
        std::cout << "Абонемент существует" << std::endl;
    }

    TerminalController::waitForClick();
}

void LibraryManager::assignEmployee(Library &lib) {
    std::cout << "Список ID сотрудников: " << std::endl;
    for (const auto &e : lib.getEmployees()) {
        std::cout << e->getId() << " ";
    }

    std::cout << std::endl;

    std::shared_ptr<Employee> e;
    while (true) {
        std::cout<<"ID сотрудника (-1 для выхода): " << std::endl;
        const int empId = CheckInput::inputIndex();
        if (empId == -1) {
            TerminalController::waitForClick();
            return;
        }
        e = lib.findEmployee(empId);

        if (e == nullptr) {
            std::cout << "Сотрудник не найден." << std::endl;
        } else {
            break;
        }
    }

    std::cout << std::endl;

    std::cout << "Список ID абониментов: " << std::endl;
    for (const auto &s : lib.getSubscriptions().getAll()) {
        std::cout << s->getId() << " ";
    }

    std::cout << std::endl;

    std::shared_ptr<Subscription> s;
    while (true) {
        std::cout << "ID абонемента (-1 для выхода): ";
        const int subId = CheckInput::inputIndex();

        if (subId == -1) {
            TerminalController::waitForClick();
            return;
        }

        s = lib.findSubscription(subId);

        if (s == nullptr) {
            std::cout << "Абонемент не найден." << std::endl;
        } else {
            break;
        }
    }

    e->takeSubscription(s);

    std::cout<<"Сотрудник начал работу." << std::endl;
    TerminalController::waitForClick();
}

void LibraryManager::releaseEmployee(Library &lib) {
    std::cout << "Список ID сотрудников: " << std::endl;
    for (const auto &e : lib.getEmployees()) {
        std::cout << e->getId() << " ";
    }

    std::cout << std::endl;

    std::shared_ptr<Employee> e;
    while (true) {
        std::cout << "ID сотрудника (-1 для выхода): ";
        const int empId = CheckInput::inputIndex();
        if (empId == -1) {
            TerminalController::waitForClick();
            return;
        }
        e = lib.findEmployee(empId);

        if (e == nullptr) {
            std::cout << "Сотрудник не найден." << std::endl;
        } else {
            break;
        }
    }

    std::cout << std::endl;

    std::cout << "Список ID абониментов: " << std::endl;
    for (const auto &s : lib.getSubscriptions().getAll()) {
        std::cout << s->getId() << " ";
    }

    std::cout << std::endl;

    e->releaseSubscription();

    std::cout<<"Сотрудник закончил работу." << std::endl;
    TerminalController::waitForClick();
}

void LibraryManager::addBookToSubscription(Library &lib) {
    TransactionMenu menu(lib);
}

void LibraryManager::printLibInfo(Library &lib) {
    lib.printInfo();
    TerminalController::waitForClick();
}

void LibraryManager::changeLibInfo(Library &lib) {
    std::string title;
    do {
        std::cout << "Введите название (не должно содержать ;): ";
        std::getline(std::cin, title);
    } while (title.find(';') != std::string::npos);

    std::string address;
    do {
        std::cout << "Введите адресс (не должно содержать ;): ";
        std::getline(std::cin, address);
    } while (address.find(';') != std::string::npos);

    lib.setOrgName(title);
    lib.setAddress(address);

    std::cout << "Изменено." << std::endl;
    TerminalController::waitForClick();
}

void LibraryManager::load(Library &lib) {
    // ввод сведений о библиотеке
    std::ifstream libraryFile("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-7/files/library.txt");
    std::string libTitle;
    std::getline(libraryFile, libTitle);

    std::string address;
    std::getline(libraryFile, address);
    libraryFile.close();

    lib.setOrgName(libTitle);
    lib.setAddress(address);

    // ввод книг
    std::ifstream booksFile("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-7/files/books.txt");

    std::string line;
    while (std::getline(booksFile, line)) {
        auto b = std::make_shared<Book>(Book());
        std::stringstream ss(line);

        std::string bookId;
        getline(ss, bookId, ';');
        const int id = std::stoi(bookId);
        b->setId(id);

        std::string bookTitle;
        getline(ss, bookTitle, ';');
        b->setTitle(bookTitle);

        std::string author;
        getline(ss, author, ';');
        b->setAuthor(author);

        std::string yearStr;
        getline(ss, yearStr, ';');
        const int year = std::stoi(yearStr);
        b->setYear(year);

        std::string totalCopiesStr;
        getline(ss, totalCopiesStr, ';');
        const int totalCopies = std::stoi(totalCopiesStr);
        b->setTotalCopies(totalCopies);

        std::string availableCopiesStr;
        getline(ss, availableCopiesStr);
        const int availableCopies = std::stoi(availableCopiesStr);
        b->setAvailableCopies(availableCopies);

        lib.addBook(b);
    }
    booksFile.close();

    // ввод читателей
    std::ifstream readersFile("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-7/files/readers.txt");
    while (std::getline(readersFile, line)) {
        auto r = std::make_shared<Reader>(Reader());
        std::stringstream ss(line);

        std::string readerId;
        getline(ss, readerId, ';');
        const int id = std::stoi(readerId);
        r->setId(id);

        std::string fullName;
        getline(ss, fullName);
        r->setFullName(fullName);

        lib.addReader(r);
    }

    // ввод абонементов
    std::ifstream subscriptionsFile("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-7/files/subscriptions.txt");
    while (std::getline(subscriptionsFile, line)) {
        auto s = std::make_shared<Subscription>(Subscription());
        std::stringstream ss(line);

        std::string subscriptionId;
        getline(ss, subscriptionId, ';');
        const int id = std::stoi(subscriptionId);
        s->setId(id);

        std::string readerIdStr;
        getline(ss, readerIdStr, ';');
        const int readerId = std::stoi(readerIdStr);
        auto r = lib.findReader(readerId);
        s->setReader(r);

        std::string amountOfBooksStr;
        getline(ss, amountOfBooksStr, ';');
        const int amountOfBooks = std::stoi(amountOfBooksStr);
        for (int i = 0; i < amountOfBooks; i++) {
            std::string bookIdStr;
            getline(ss, bookIdStr, ';');
            const int bookId = std::stoi(bookIdStr);
            auto b = lib.findBook(bookId);
            s->addBook(b);
        }

        s->setWorkerCount(0);

        lib.addSubscription(s);
    }

    subscriptionsFile.close();

    // ввод сотрудников
    std::ifstream employeesFile("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-7/files/employees.txt");
    while (std::getline(employeesFile, line)) {
        auto e = std::make_shared<Employee>(Employee());
        std::stringstream ss(line);

        std::string bookId;
        getline(ss, bookId, ';');
        const int id = std::stoi(bookId);
        e->setId(id);

        std::string fullName;
        getline(ss, fullName, ';');
        e->setFullName(fullName);

        std::string position;
        getline(ss, position, ';');
        e->setPosition(position);

        std::string subIdStr;
        getline(ss, subIdStr);
        const int subId = std::stoi(subIdStr);
        if (subId != -1) {
            auto sub = lib.findSubscription(subId);
            e->takeSubscription(sub);
        }

        lib.addEmployee(e);
    }

    employeesFile.close();
}

void LibraryManager::save(Library &lib) {
    std::ofstream libraryFile("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-7/files/library.txt", std::ios::out);
    libraryFile << lib.getOrgName() << std::endl << lib.getAddress() << std::endl;
    libraryFile.close();

    std::ofstream booksFile("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-7/files/books.txt", std::ios::out);
    for (const auto &b : lib.getBooks().getAll()) {
        booksFile << b->getId() << ";" << b->getTitle() << ";" << b->getAuthor() << ";" << b->getYear() << ";" << b->getTotalCopies() << ";" << b->getAvailableCopies() << std::endl;
    }
    booksFile.close();

    std::ofstream employeesFile("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-7/files/employees.txt", std::ios::out);
    for (const auto &e : lib.getEmployees()) {
        employeesFile << e->getId() << ";" << e->getFullName() << ";" << e->getPosition() << ";" << (e->getCurrentSub() != nullptr ? e->getCurrentSub()->getId() : -1) << std::endl;
    }
    employeesFile.close();

    std::ofstream readersFile("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-7/files/readers.txt", std::ios::out);
    for (const auto &r : lib.getReaders().getAll()) {
        readersFile << r->getId() << ";" << r->getFullName() << std::endl;
    }
    readersFile.close();

    std::ofstream subscriptionsFile("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-7/files/subscriptions.txt", std::ios::out);
    for (const auto &s : lib.getSubscriptions().getAll()) {
        subscriptionsFile << s->getId() << ";" << s->getReader()->getId() << ";" << s->getBooks().size() << ";";
        for (const auto &book : s->getBooks()) {
            subscriptionsFile << book->getId() << ";";
        }
        subscriptionsFile << std::endl;
    }
    subscriptionsFile.close();

}