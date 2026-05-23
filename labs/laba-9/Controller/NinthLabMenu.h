#ifndef OOPAD_2026_SEVENLABMENU_H
#define OOPAD_2026_SEVENLABMENU_H

#include "../../../libs/Menu.h"
#include "../Entities/Library.h"

class EighthLabMenu : public Menu {
    enum menuPoints {
        ADD_BOOK = 1, ADD_READER, ADD_EMPLOYEE, CREATE_SUBSCRIPTION, ASSIGN_SUBSCRIPTION,
        RELEASE_SUBSCRIPTION, ADD_BOOK_TO_SUBSCRIPTION, CHANGE_LIB_INFO, SAVE_INFO, SHOW_ALL
    };
    Library lib;
    void doMenuAction(int) override;
public:
    EighthLabMenu();
};


#endif //OOPAD_2026_SEVENLABMENU_H