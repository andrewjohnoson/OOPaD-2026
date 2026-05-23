#ifndef OOPAD_2026_SIXTHLABMENU_H
#define OOPAD_2026_SIXTHLABMENU_H

#include "../../../libs/Menu.h"

class SixthLabMenu : public Menu {
    enum menuPoints {
        SHOW_PROCESSES = 1, SHOW_HUMAN_ACTIVITIES, SHOW_GAMES, SHOW_ESPORTS, SHOW_COMPETITIVE_SPORTS
    };
    void doMenuAction(int) override;
};


#endif //OOPAD_2026_SIXTHLABMENU_H