#include "NinthLabMenu.h"

#include <iostream>

#include "StoreManager.h"

using sm = StoreManager;

NinthLabMenu::NinthLabMenu() {
    sm::load(store_);
}

void NinthLabMenu::doMenuAction(int selected) {
    if (selected == menuCounter + 1) {
        sm::save(store_);
        std::cout << "Выход." << std::endl;
        exit(0);
    }

    if (selected == ADD_BUILDING_MATERIAL) {
        sm::addBuildingMaterial(store_);
    }

    if (selected == ADD_TOOL) {
        sm::addTool(store_);
    }

    if (selected == CREATE_ORDER) {
        sm::createOrder(store_);
    }

    if (selected == ADD_ITEM_TO_ORDER) {
        sm::addItemToOrder(store_);
    }

    if (selected == CONFIRM_ORDER) {
        sm::confirmOrder(store_);
    }

    if (selected == CANCEL_ORDER) {
        sm::cancelOrder(store_);
    }

    if (selected == SHOW_CATALOG) {
        sm::printCatalog(store_);
    }

    if (selected == SHOW_ORDERS) {
        sm::printOrders(store_);
    }

    if (selected == CHANGE_STORE_INFO) {
        sm::changeStoreInfo(store_);
    }

    if (selected == SAVE_INFO) {
        sm::save(store_);
    }

    if (selected == DEMO_EXCEPTIONS) {
        sm::showExceptionDemo();
    }
}
