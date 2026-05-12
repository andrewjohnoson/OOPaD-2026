#ifndef OOPAD_2026_FIFTHLABMENU_H
#define OOPAD_2026_FIFTHLABMENU_H

#include "../../../libs/Menu.h"

class FifthLabMenu : public Menu {
    enum menuPoints {
        ADD_SHAPE = 1, SHOW_ALL_SHAPES, SHOW_EQUAL_SHAPES,
    };

    void doMenuAction(int);
};

#endif //OOPAD_2026_FIFTHLABMENU_H