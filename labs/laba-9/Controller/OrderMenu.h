// OrderMenu.h
#ifndef OOPAD_2026_ORDERMENU_H
#define OOPAD_2026_ORDERMENU_H

#include "../../../libs/Menu.h"

#include "../Entities/Store.h"

class OrderMenu : public Menu {
    enum points {
        SELECT_ORDER = 1,
        ADD_PRODUCT,
        REMOVE_PRODUCT,
        SHOW_ORDER
    };

    Store &store_;
    std::shared_ptr<Order> currentOrder_;
    bool isActive = false;

    void doMenuAction(int) override;
    void showMenu() override;

    void selectOrder();
    void addProduct();
    void removeProduct();
    void showOrder() const;

public:
    OrderMenu(Store &);

};


#endif //OOPAD_2026_ORDERMENU_H