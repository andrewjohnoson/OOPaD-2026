#include "SevenLabMenu.h"

#include <iostream>

#include "LibraryManager.h"

using lm = LibraryManager;

SevenLabMenu::SevenLabMenu() {
    lm::load(lib);
}

void SevenLabMenu::doMenuAction(int selected) {
    if (selected == menuCounter + 1) {
        lm::save(lib);
        std::cout << "Выход." << std::endl;
        exit(0);
    }

    if (selected == ADD_BOOK) {
        lm::addBook(lib);
    }

    if (selected == ADD_READER) {
        lm::addReader(lib);
    }

    if (selected == ADD_EMPLOYEE) {
        lm::addEmployee(lib);
    }

    if (selected == CREATE_SUBSCRIPTION) {
        lm::createSubscription(lib);
    }

    if (selected == ASSIGN_SUBSCRIPTION) {
        lm::assignEmployee(lib);
    }

    if (selected == RELEASE_SUBSCRIPTION) {
        lm::releaseEmployee(lib);
    }

    if (selected == ADD_BOOK_TO_SUBSCRIPTION) {
        lm::addBookToSubscription(lib);
    }

    if (selected == SHOW_ALL) {
        lm::printLibInfo(lib);
    }

    if (selected == CHANGE_LIB_INFO) {
        lm::changeLibInfo(lib);
    }

    if (selected == SAVE_INFO) {
        lm::save(lib);
    }
}
