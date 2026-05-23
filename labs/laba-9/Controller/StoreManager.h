// StoreManager.h
#ifndef OOPAD_2026_STOREMANAGER_H
#define OOPAD_2026_STOREMANAGER_H

#include "../Entities/Store.h"

class StoreManager {
public:
    static void addBuildingMaterial(Store &);
    static void addTool(Store &);
    static void createOrder(Store &);
    static void addItemToOrder(Store &);
    static void confirmOrder(Store &);
    static void cancelOrder(Store &);
    static void printCatalog(Store &);
    static void printOrders(Store &);
    static void changeStoreInfo(Store &);
    static void load(Store &);
    static void save(Store &);
    static void showExceptionDemo();

    static int generateId();
    static void storeTerminate();
    static std::string inputStringSafe(const std::string &);
};


#endif //OOPAD_2026_STOREMANAGER_H