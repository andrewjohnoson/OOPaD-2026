// Library.cpp
#include "Library.h"

Library::~Library() {
    employees.clear();
}

void Library::addBook(const std::shared_ptr<Book> &book) {
    books.add(book);
}

std::shared_ptr<Book> Library::findBook(const int id) {
    return books.findById(id);
}

const Catalog<Book>& Library::getBooks() const {
    return books;
}

void Library::addReader(const std::shared_ptr<Reader> &reader) {
    readers.add(reader);
}

std::shared_ptr<Reader> Library::findReader(const int id) const {
    return readers.findById(id);
}

const Catalog<Reader>& Library::getReaders() const {
    return readers;
}

void Library::addEmployee(const std::shared_ptr<Employee> &emp) {
    employees.push_back(emp);
}

std::shared_ptr<Employee> Library::findEmployee(const int id) const {
    for (auto e : employees)
        if (e->getId() == id) return e;
    return nullptr;
}

const std::vector<std::shared_ptr<Employee>>& Library::getEmployees() const {
    return employees;
}

void Library::addSubscription(const std::shared_ptr<Subscription> &sub) {
    subscriptions.add(sub);
}

std::shared_ptr<Subscription> Library::findSubscription(const int id) const {
    return subscriptions.findById(id);
}

std::shared_ptr<Subscription> Library::findSubscriptionByUser(const int id) const {
    for (auto sub : subscriptions.getAll()) {
        if (sub->getReader()->getId() == id) return sub;
    }
    return nullptr;
}

const Catalog<Subscription>& Library::getSubscriptions() const {
    return subscriptions;
}

void Library::printInfo() const {
    std::cout << "=== БИБЛИОТЕКА ===" << std::endl;
    Organisation::print();
    std::cout << std::endl;

    std::cout << "  Книг в каталоге: " << books.getCount() << std::endl;

    for (const auto &book : books.getAll()) {
        book->print();
    }
    std::cout << std::endl;

    std::cout << "  Читателей: " << readers.getCount() << std::endl;

    for (const auto &reader : readers.getAll()) {
        reader->print();
    }
    std::cout << std::endl;

    std::cout << "  Сотрудников: " << employees.size() << std::endl;

    for (const auto &employee : employees) {
        employee->print();
    }
    std::cout << std::endl;

    std::cout << "  Абонементов: " << subscriptions.getCount() << std::endl;

    for (const auto &subscription : subscriptions.getAll()) {
        subscription->print();
    }
    std::cout << std::endl;
}