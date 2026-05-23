// TransactionMenu.h
#ifndef OOPAD_2026_TRANSACTIONMENU_H
#define OOPAD_2026_TRANSACTIONMENU_H

#include "../../../libs/Menu.h"
#include "../Entities/Library.h"

class TransactionMenu : public Menu {
    enum points {
        ADD_BOOK = 1, SHOW, COMMIT, ROLLBACK
    };

    bool isActive;

    Library &lib;
    std::shared_ptr<Subscription> activeSubscription;

    void doMenuAction(int) override;
    void showMenu() override;
public:
    TransactionMenu(Library &lib);
};


#endif //OOPAD_2026_TRANSACTIONMENU_H