// TerminalController.cpp
#include "TerminalController.h"

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <sys/wait.h>

char TerminalController::getch() {
    termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ECHO|ICANON);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    read(STDIN_FILENO, &ch, 1);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void TerminalController::disableInput() {
    termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ECHO|ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void TerminalController::enableInput() {
    termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= (ECHO|ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void TerminalController::clearTerminal() {
    std::cout << "\033[2J\033[3J\033[H";
}

void TerminalController::openExecutable(const std::string& pathToExecutable) {
    disableInput();
    std::cout << "Запускаем." << std::endl;
    sleep(1);

    pid_t pid = fork();

    if (pid == 0) {
        enableInput();
        if (execl(pathToExecutable.c_str(), pathToExecutable.c_str(), NULL) == -1) {
            std::cout << "Файл не найден. Подождите.";
            disableInput();
        }

        exit(1);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        std::cout << "Не удалось создать процесс. Подождите.";
        disableInput();
    }

    sleep(3);
    enableInput();
}