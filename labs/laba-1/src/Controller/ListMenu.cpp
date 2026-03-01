// ListMenu.cpp
#include "ListMenu.h"

#include "../../../../libs/TerminalController.h"
#include "ListIntController.h"
#include "ListStringController.h"

#include <vector>
#include <iostream>

void ListMenu::init(int param) {
    TerminalController::clearTerminal();

    this->menuCounter = this->menuPoints.size();
    this->param = param;

    this->showMenu();
}

void ListMenu::showMenu() {
    while (true) {
        if (this->param == this->LINKED_LIST_INT) {
            std::cout << "Работа с LinkedListInt" << std::endl
                << "===============================================" << std::endl << std::endl;
        }

        if (this->param == this->LINKED_LIST_STRING) {
            std::cout << "Работа с LinkedListString" << std::endl
                << "===============================================" << std::endl << std::endl;
        }
        for (int i = 1; i <= this->menuCounter; i++) {
            if (i == this->selected) {
                std::cout << "--> " << "\033[7m" << i << ". " << this->menuPoints[i - 1] << "\033[0m" << std::endl;
                continue;
            }
            std::cout << "    " << i << ". " << this->menuPoints[i - 1] << std::endl;
        }

        if (this->selected == this->menuCounter + 1) {
            std::cout << "--> " << "\033[7m" << this->menuCounter + 1 << ". Выйти из приложения." << "\033[0m" << std::endl;
        } else {
            std::cout << "    " << this->menuCounter + 1 << ". Выйти из приложения." << std::endl;
        }

        const int button = this->getButton();

        if (button == this->DOWN_ARROW_BUTTON) {
            this->selected++;
            if (this->selected > this->menuCounter + 1) {
                this->selected = 1;
            }

            TerminalController::clearTerminal();
        }

        if (button == this->UP_ARROW_BUTTON) {
            selected--;
            if (selected < 1) {
                this->selected = this->menuCounter + 1;
            }

            TerminalController::clearTerminal();
        }

        if (button == this->ENTER_BUTTON && this->selected == this->EXIT) {
            TerminalController::clearTerminal();
            break;
        }

        if (button == this->ENTER_BUTTON) {
            TerminalController::clearTerminal();

            this->doMenuAction(this->selected);
            TerminalController::clearTerminal();
        }
        TerminalController::clearTerminal();
    }
}

void ListMenu::doMenuAction(const int selected) {
    if (selected == this->CREATE_OBJECTS_ARRAY) {
        if (param == this->LINKED_LIST_INT) {
            ListIntController::createArray();
        } else if (param == this->LINKED_LIST_STRING) {
            ListStringController::createArray();
        }
    }

    if (selected == this->READ_OBJECTS_DATA) {
        if (param == this->LINKED_LIST_INT) {
            ListIntController::inputData();
        } else if (param == this->LINKED_LIST_STRING) {
            ListStringController::inputData();
        }
    }

    if (selected == this->OUTPUT_OBJECTS_DATA) {
        if (param == this->LINKED_LIST_INT) {
            ListIntController::outputData();
        } else if (param == this->LINKED_LIST_STRING) {
            ListStringController::outputData();
        }
    }

    if (selected == this->ADD_ELEMENT_TO_LIST) {
        if (param == this->LINKED_LIST_INT) {
            ListIntController::addElementInList();
        } else if (param == this->LINKED_LIST_STRING) {
            ListStringController::addElementInList();
        }
    }

    if (selected == this->FIND_ELEMENT_IN_LIST) {
        if (param == this->LINKED_LIST_INT) {
            ListIntController::findElementInList();
        } else if (param == this->LINKED_LIST_STRING) {
            ListStringController::findElementInList();
        }
    }

    if (selected == this->REMOVE_ELEMENT_FROM_LIST) {
        if (param == this->LINKED_LIST_INT) {
            ListIntController::removeElementFromList();
        } else if (param == this->LINKED_LIST_STRING) {
            ListStringController::removeElementFromList();
        }
    }

    if (selected == this->SORT_LIST) {
        if (param == this->LINKED_LIST_INT) {
            ListIntController::sortList();
        } else if (param == this->LINKED_LIST_STRING) {
            ListStringController::sortList();
        }
    }
}
