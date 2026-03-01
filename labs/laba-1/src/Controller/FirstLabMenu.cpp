// FirstLabMenu.cpp
#include "FirstLabMenu.h"
#include "ListMenu.h"

#include <iostream>

void FirstLabMenu::doMenuAction(const int selected) {
    if (selected == this->menuCounter + 1) {
        std::cout << "Выход." << std::endl;
        exit(0);
    }

    if (selected == this->LINKED_LIST_INT) {
        ListMenu listMenu;
        listMenu.init(this->LINKED_LIST_INT);
    }

    if (selected == this->LINKED_LIST_STRING) {
        ListMenu listMenu;
        listMenu.init(this->LINKED_LIST_STRING);
    }
}
