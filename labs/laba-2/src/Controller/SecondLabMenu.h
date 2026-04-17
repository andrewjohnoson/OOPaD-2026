#ifndef OOPAD_2026_SECONDLABMENU_H
#define OOPAD_2026_SECONDLABMENU_H

#include "../../../../libs/Menu.h"
#include "../Entities/Array.h"

class SecondLabMenu : public Menu {
    const int CREATE_INT_ARRAY = 1, CREATE_FLOAT_ARRAY = 2, SORT_ARRAY = 3, OUTPUT_ARRAY = 4, DELETE_ARRAY = 5;
    Array array;
protected:
    void doMenuAction(int) override;
};


#endif //OOPAD_2026_SECONDLABMENU_H