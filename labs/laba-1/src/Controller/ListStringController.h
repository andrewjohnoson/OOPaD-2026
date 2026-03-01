// ListStringController.h
#ifndef OOPAD_2026_LISTSTRINGCONTROLLER_H
#define OOPAD_2026_LISTSTRINGCONTROLLER_H

#include "../Entities/LinkedListString.h"

#include <string>

class ListStringController {
public:
    static std::vector<LinkedListString> listsString;
    static int listsStringSize;
    static std::string outputFilePath;

    static void createArray();
    static void inputData();
    static void outputData();
    static void outputListsId();
    static void sortList();
    static void addElementInList();
    static void findElementInList();
    static void removeElementFromList();

    static LinkedListString* findListStringByID(int);
};


#endif //OOPAD_2026_LISTSTRINGCONTROLLER_H