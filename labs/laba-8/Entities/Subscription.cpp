// Subscription.cpp
#include "Subscription.h"

#include <iostream>

#include "../../../libs/TerminalController.h"

Subscription::~Subscription() {
    books.clear();
}

int Subscription::getId() const {
    return id;
}

std::shared_ptr<Reader> Subscription::getReader() const {
    return reader;
}

const std::vector<std::shared_ptr<Book>>& Subscription::getBooks() const {
    return books;
}

int Subscription::getWorkerCount() const {
    return workerCount;
}

void Subscription::setId(const int i) {
    id = i;
}

void Subscription::setReader(const std::shared_ptr<Reader> &r) {
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

void Subscription::addBook(const std::shared_ptr<Book> &book) {
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
    for (const auto &b : books) {
        std::cout << "      - [" << b->getId() << "] " << b->getTitle() << "\n";
    }
}

void Subscription::beginTransaction() {
    transaction = Transaction<std::vector<std::shared_ptr<Book>>>(books);
    transaction.beginTransaction();
}

void Subscription::commit() {
    transaction.commit();
}

void Subscription::rollback() {
    if (!transaction.hasActiveTransaction()) return;

    const auto& snapshot = transaction.get();

    for (const auto& b : books) {
        bool inSnapshot = false;
        for (const auto& sb : snapshot) {
            if (sb.get() == b.get()) {
                inSnapshot = true;
                break;
            }
        }
        if (!inSnapshot) b->returnOne();
    }

    for (const auto& sb : snapshot) {
        bool inCurrent = false;
        for (const auto& b : books) {
            if (b.get() == sb.get()) { inCurrent = true; break; }
        }
        if (!inCurrent) sb->takeOne();
    }

    transaction.deleteTransaction();
    books = transaction.get();
}

bool Subscription::hasActiveTransaction() {
    return transaction.hasActiveTransaction();
}
