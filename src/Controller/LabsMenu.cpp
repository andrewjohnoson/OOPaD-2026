#include "LabsMenu.h"
#include "../../libs/TerminalController.h"

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void LabsMenu::init() {
    TerminalController::clearTerminal();

    this->setLabsFolderPath("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs");

    this->menuCounter = this->countAmountOfLabs();

    this->showMenu();
}

int LabsMenu::countAmountOfLabs() {
    int amountOfLabs = 0;

    for (const auto& entry : fs::directory_iterator(this->labsFolderPath)) {
        amountOfLabs++;
    }

    return amountOfLabs;
}


void LabsMenu::setLabsFolderPath(std::string path) { labsFolderPath = path; }

void LabsMenu::showMenu() {
    while (true) {
    std::cout << "Список лабораторных работ ООПиП 2026" << std::endl << "====================================" << std::endl << std::endl;
        for (int i = 1; i <= this->menuCounter; i++) {
            if (i == this->selected) {
                std::cout << "--> " << "\033[7m" << i << ". Запустить " << i << "-ю лабу" << "\033[0m" << std::endl;
                continue;
            }
            std::cout << "    " << i << ". Запустить " << i << "-ю лабу" << std::endl;

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

void LabsMenu::doMenuAction(const int selected) {
    if (selected == this->menuCounter + 1) {
        exit(0);
    }

    // const std::string pathToExecutable = "/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/cmake-build-debug"
    //     + std::to_string(selected) + "/laba-" + std::to_string(selected);

    const std::string pathToExecutable = "/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/cmake-build-debug/laba-"
                + std::to_string(selected);

    TerminalController::openExecutable(pathToExecutable);
}