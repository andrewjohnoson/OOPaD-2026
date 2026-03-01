// Menu.cpp
#include "Menu.h"
#include "TerminalController.h"

#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>

void Menu::init(const std::vector<std::string> &menuSettings) {
    TerminalController::clearTerminal();

    this->menuPoints = menuSettings;
    this->menuCounter = this->menuPoints.size();

    this->showMenu();
}

void Menu::init(const std::vector<std::string> &menuSettings, std::string menuTitle) {
    TerminalController::clearTerminal();

    this->menuPoints = menuSettings;
    this->menuCounter = this->menuPoints.size();
    this->menuTitle = menuTitle;

    this->showMenu();
}

void Menu::init(std::string menuTitle) {
    TerminalController::clearTerminal();

    this->menuTitle = menuTitle;

    this->showMenu();
}

void Menu::showMenu() {
    while (true) {
        std::cout << this->menuTitle << std::endl << "================================" << std::endl << std::endl;
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

        if (button == this->ENTER_BUTTON) {
            TerminalController::clearTerminal();

            this->doMenuAction(this->selected);
            TerminalController::clearTerminal();
        }
        TerminalController::clearTerminal();
    }
}

void Menu::doMenuAction(const int selected) {
    if (selected == this->menuCounter + 1) {
        exit(0);
    }

    std::cout << "Поведение не определено." << std::endl;
    sleep(2);
}

int Menu::getButton() {
    const char ch = TerminalController::getch();

    if (ch == 27) {
        const char c1 = TerminalController::getch(); // [
        const char c2 = TerminalController::getch(); // код стрелки

        if (c1 == '[')
        {
            if (c2 == 'A') { // "up"
                // std::cout << "up";
                return this->UP_ARROW_BUTTON;
            }
            if (c2 == 'B') { // "down"
                // std::cout << "down";
                return this->DOWN_ARROW_BUTTON;
            }
        }
    }

    if (ch == 10) {
        return this->ENTER_BUTTON;
    }

    return this->NOT_SUITABLE_BUTTON;
}