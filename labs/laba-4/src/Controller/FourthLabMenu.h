#ifndef OOPAD_2026_FOURTHLABMENU_H
#define OOPAD_2026_FOURTHLABMENU_H

#include "../../../../libs/Menu.h"

class FourthLabMenu : public Menu {
    const int ADD_ROUTE = 1, CHANGE_ROUTE = 2, OUTPUT_ROUTE = 3, DELETE_ROUTE = 4;
    void doMenuAction(int) override;
};


#endif //OOPAD_2026_FOURTHLABMENU_H