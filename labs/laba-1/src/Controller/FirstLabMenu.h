// FirstLabMenu.h
#ifndef OOPAD_2026_FIRSTLABAMENU_H
#define OOPAD_2026_FIRSTLABAMENU_H

#include "../../../../libs/Menu.h"

class FirstLabMenu : public Menu {
protected:
    void doMenuAction(int) override;
private:
    const int LINKED_LIST_INT = 1, LINKED_LIST_STRING = 2;
};


#endif //OOPAD_2026_FIRSTLABAMENU_H