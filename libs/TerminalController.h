// TerminalController.h
#ifndef OOPAD_2026_TERMINALCONTROLLER_H
#define OOPAD_2026_TERMINALCONTROLLER_H

#include <string>

class TerminalController {
public:
    static char getch();
    static void clearTerminal();
    static void openExecutable(const std::string &);
    static void disableInput();
    static void enableInput();
};


#endif //OOPAD_2026_TERMINALCONTROLLER_H