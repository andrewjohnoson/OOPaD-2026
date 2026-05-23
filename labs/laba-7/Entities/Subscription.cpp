// Subscription.cpp
#include "Subscription.h"

#include <iostream>

#include "../../../libs/TerminalController.h"

Subscription::~Subscription() {
    for (const Book* b : books) {
        delete b;
    }
    books.clear();
}

int Subscription::getId() const {
    return id;
}

Reader* Subscription::getReader() const {
    return reader;
}

const std::vector<Book*>& Subscription::getBooks() const {
    return books;
}

int Subscription::getWorkerCount() const {
    return workerCount;
}

void Subscription::setId(const int i) {
    id = i;
}

void Subscription::setReader(Reader* r) {
    reader = r;
}

void Subscription::setWorkerCount(const int w) {
    workerCount = w;
}

// Блокировка абонемента сотрудником
void Subscription::lock() {
    ++workerCount;
}

// Снятие блокировки
void Subscription::unlock() {
    if (workerCount > 0) --workerCount;
}

// Абонемент доступен для редактирования?
bool Subscription::isEditable() const {
    return workerCount == 0;
}

void Subscription::addBook(Book* book) {
    if (!isEditable())
        throw std::runtime_error("Абонемент заблокирован — с ним работает сотрудник");
    books.push_back(book);
    book->takeOne();
}

void Subscription::removeBook(const int bookId) {
    if (!isEditable()) {
        std::cout << "Абонемент обрабатывается.";
        TerminalController::waitForClick();
        return;
    }
    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it)->getId() == bookId) {
            (*it)->returnOne();
            books.erase(it);
            return;
        }
    }
}

void Subscription::print() const {
    std::cout << "  Абонемент [" << id << "]: читатель — ";
    if (reader) std::cout << reader->getFullName();
    else std::cout << "не задан";
    std::cout << std::endl
              << "  Статус: " << (isEditable() ? "свободен" : "заблокирован")
              << " (сотрудников: " << workerCount << ")\n";
    std::cout << "    Книги (" << books.size() << "):\n";
    for (Book* b : books) {
        std::cout << "      - [" << b->getId() << "] " << b->getTitle() << "\n";
    }
}