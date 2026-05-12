// ShapesController.h
#ifndef OOPAD_2026_SHAPESCONTROLLER_H
#define OOPAD_2026_SHAPESCONTROLLER_H

#include <vector>

#include "../Entities/Shape.h"

class ShapesController {
    static std::vector <Shape*> shapesList;
    static int idCounter;
public:
    static void addShapes();
    static void showAllShapes();
    static void showEqualShapes();
};


#endif //OOPAD_2026_SHAPESCONTROLLER_H