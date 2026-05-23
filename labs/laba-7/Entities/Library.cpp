// Library.cpp
#include "Library.h"

Library::~Library() {
    for (Employee* e : employees) delete e;
    employees.clear();
}

void Library::addBook(Book* book) {
    books.add(book);
}

Book* Library::findBook(const int id) {
    return books.findById(id);
}

const Catalog<Book>& Library::getBooks() const {
    return books;
}

void Library::addReader(Reader* reader) {
    readers.add(reader);
}

Reader* Library::findReader(int id) const {
    return readers.findById(id);
}

const Catalog<Reader>& Library::getReaders() const {
    return readers;
}

void Library::addEmployee(Employee* emp) {
    employees.push_back(emp);
}

Employee* Library::findEmployee(const int id) const {
    for (Employee* e : employees)
        if (e->getId() == id) return e;
    return nullptr;
}

const std::vector<Employee*>& Library::getEmployees() const {
    return employees;
}

void Library::addSubscription(Subscription* sub) {
    subscriptions.add(sub);
}

Subscription* Library::findSubscription(const int id) const {
    return subscriptions.findById(id);
}

Subscription* Library::findSubscriptionByUser(const int id) const {
    for (Subscription* sub : subscriptions.getAll()) {
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

    for (const Book *book : books.getAll()) {
        book->print();
    }
    std::cout << std::endl;

    std::cout << "  Читателей: " << readers.getCount() << std::endl;

    for (const Reader *reader : readers.getAll()) {
        reader->print();
    }
    std::cout << std::endl;

    std::cout << "  Сотрудников: " << employees.size() << std::endl;

    for (const Employee *employee : employees) {
        employee->print();
    }
    std::cout << std::endl;

    std::cout << "  Абонементов: " << subscriptions.getCount() << std::endl;

    for (const Subscription *subscription : subscriptions.getAll()) {
        subscription->print();
    }
    std::cout << std::endl;
}