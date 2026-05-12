#include "FifthLabMenu.h"
#include "ShapesController.h"

#include <iostream>

void FifthLabMenu::doMenuAction(const int selected) {
    if (selected == menuCounter + 1) {
        std::cout << "Выход." << std::endl;
        exit(0);
    }

    if (selected == ADD_SHAPE) {
        ShapesController::addShapes();
    }

    if (selected == SHOW_ALL_SHAPES) {
        ShapesController::showAllShapes();
    }

    if (selected == SHOW_EQUAL_SHAPES) {
        ShapesController::showEqualShapes();
    }
}
