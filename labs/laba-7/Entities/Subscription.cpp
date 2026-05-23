#include "Subscirption.h"

#include <iostream>

int Subscirption::getId() const {
    return id;
}

Reader* Subscirption::getReader() const {
    return reader;
}

const std::vector<Book*>& Subscirption::getBooks() const {
    return books;
}

std::string Subscirption::getIssueDate() const {
    return issueDate;
}

std::string Subscirption::getReturnDate() const {
    return returnDate;
}

int Subscirption::getWorkerCount() const {
    return workerCount;
}

void Subscirption::setId(int i) { id = i; }
void Subscirption::setReader(Reader* r) { reader = r; }
void Subscirption::setIssueDate(const std::string& d) { issueDate = d; }
void Subscirption::setReturnDate(const std::string& d) { returnDate = d; }

// Блокировка абонемента сотрудником
void Subscirption::lock() { ++workerCount; }

// Снятие блокировки
void Subscirption::unlock() {
    if (workerCount > 0) --workerCount;
}

// Абонемент доступен для редактирования?
bool Subscirption::isEditable() const { return workerCount == 0; }

void Subscirption::addBook(Book* book) {
    if (!isEditable())
        throw std::runtime_error("Абонемент заблокирован — с ним работает сотрудник");
    books.push_back(book);
    book->takeOne();
}

void Subscirption::removeBook(int bookId) {
    if (!isEditable())
        throw std::runtime_error("Абонемент заблокирован — с ним работает сотрудник");
    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it)->getId() == bookId) {
            (*it)->returnOne();
            books.erase(it);
            return;
        }
    }
}

void Subscirption::print() const {
    std::cout << "  Абонемент [" << id << "]: читатель — ";
    if (reader) std::cout << reader->getFullName();
    else std::cout << "не задан";
    std::cout << "\n    Выдан: " << issueDate
              << ", Вернуть до: " << returnDate
              << ", Статус: " << (isEditable() ? "свободен" : "заблокирован")
              << " (сотрудников: " << workerCount << ")\n";
    std::cout << "    Книги (" << books.size() << "):\n";
    for (Book* b : books) {
        std::cout << "      - [" << b->getId() << "] " << b->getTitle() << "\n";
    }
}