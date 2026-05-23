#ifndef OOPAD_2026_NINTHLABMENU_H
#define OOPAD_2026_NINTHLABMENU_H

#include "../../../libs/Menu.h"
#include "../Entities/Store.h"

class NinthLabMenu : public Menu {
    enum menuPoints_ {
        ADD_BUILDING_MATERIAL = 1,
        ADD_TOOL,
        CREATE_ORDER,
        ADD_ITEM_TO_ORDER,
        CONFIRM_ORDER,
        CANCEL_ORDER,
        SHOW_CATALOG,
        SHOW_ORDERS,
        CHANGE_STORE_INFO,
        SAVE_INFO,
        DEMO_EXCEPTIONS
    };

    Store store_;

    void doMenuAction(int) override;
public:
    NinthLabMenu();
};


#endif //OOPAD_2026_NINTHLABMENU_H