// ListIntController.h
#ifndef OOPAD_2026_LISTINTCONTROLLER_H
#define OOPAD_2026_LISTINTCONTROLLER_H

#include <vector>
#include <string>
#include "../Entities/LinkedListInt.h"

class ListIntController {
public:
    static std::vector<LinkedListInt> listsInt;
    static int listsIntSize;
    static std::string outputFilePath;

    static void createArray();
    static void inputData();
    static void outputData();
    static void sortList();
    static void outputListsId();
    static void addElementInList();
    static void findElementInList();
    static void removeElementFromList();

    static LinkedListInt* findListIntByID(int);
};


#endif //OOPAD_2026_LISTINTCONTROLLER_H