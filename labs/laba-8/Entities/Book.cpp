// Book.cpp
#include "Book.h"

#include <iostream>

int Book::getId() const {
    return id;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

int Book::getTotalCopies() const {
    return totalCopies;
}

int Book::getAvailableCopies() const {
    return availableCopies;
}

void Book::setId(int i) {
    id = i;
}

void Book::setTitle(const std::string& t) {
    title = t;
}

void Book::setAuthor(const std::string& a) {
    author = a;
}

void Book::setYear(int y) {
    year = y;
}

void Book::setTotalCopies(int c) {
    totalCopies = c;
}

void Book::setAvailableCopies(int c) {
    availableCopies = c;
}

bool Book::takeOne() {
    if (availableCopies > 0) {
        --availableCopies;
        return true;
    }
    return false;
}

void Book::returnOne() {
    if (availableCopies < totalCopies) {
        ++availableCopies;
    }
}

void Book::print() const {
    std::cout << "  [" << id << "] \"" << title << "\" — " << author
              << " (" << year << ")"
              << ", экз.: " << availableCopies << "/" << totalCopies << std::endl;
}