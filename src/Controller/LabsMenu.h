#ifndef OOPAD_2026_LABSMENU_H
#define OOPAD_2026_LABSMENU_H

#include "../../libs/Menu.h"
#include <string>

class LabsMenu : public Menu {
protected:
    void showMenu();
    void doMenuAction(int number);
public:
    void init();
private:
    std::string labsFolderPath;

    void setLabsFolderPath(std::string labsFolderPath);
    int countAmountOfLabs();
};


#endif //OOPAD_2026_LABSMENU_H