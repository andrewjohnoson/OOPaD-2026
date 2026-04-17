#include "SecondLabMenu.h"

#include <iostream>

void SecondLabMenu::doMenuAction(const int selected) {
    if (selected == this->menuCounter + 1) {
        std::cout << "Выход." << std::endl;
        exit(0);
    }

    if (selected == CREATE_INT_ARRAY) {
        array.inputArray(Array::INT_ARRAY);
    }

    if (selected == CREATE_FLOAT_ARRAY) {
        array.inputArray(Array::FLOAT_ARRAY);
    }

    if (selected == SORT_ARRAY) {
        array.sortPos();
    }

    if (selected == OUTPUT_ARRAY) {
        array.outputArray();
    }

    if (selected == DELETE_ARRAY) {
        array.deleteArray();
    }
}