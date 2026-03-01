// Menu.h
#ifndef OOPAD_2026_MENU_H
#define OOPAD_2026_MENU_H

#include <vector>
#include <string>

class Menu {
protected:
    std::vector<std::string> menuPoints;
    std::string menuTitle = "";
    const int UP_ARROW_BUTTON = 0, DOWN_ARROW_BUTTON = 1, ENTER_BUTTON = 2, NOT_SUITABLE_BUTTON = -1;
    int selected = 1, menuCounter = 0;

    virtual void showMenu();
    virtual void doMenuAction(int);
    int getButton();
public:
    void init(const std::vector<std::string> &);
    void init(const std::vector<std::string> &, std::string);
    void init(std::string);
};

#endif //OOPAD_2026_MENU_H