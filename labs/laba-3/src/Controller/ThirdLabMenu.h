#ifndef OOPAD_2026_THIRDLABAMENU_H
#define OOPAD_2026_THIRDLABAMENU_H

#include "../../../../libs/Menu.h"
#include "../Entity/Distance.h"

class ThirdLabMenu : public Menu {
    const int INPUT_FIRST_DISTANCE = 1, INPUT_SECOND_DISTANCE = 2, SUM_DISTANCES = 3,
            DIFFERENCE_DISTANCE = 4, CHECK_EQUALITY = 5, OUTPUT_DISTANCES = 6;
    Distance d1, d2;
protected:
    void doMenuAction(int) override;
};


#endif //OOPAD_2026_THIRDLABAMENU_H