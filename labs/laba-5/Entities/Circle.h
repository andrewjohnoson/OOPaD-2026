// Circle.h
#ifndef OOPAD_2026_CIRCLE_H
#define OOPAD_2026_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
    double radius;
public:
    Circle() : Shape("белый", "круг"), radius(0.0) {};
    Circle(double);
    Circle(const Circle &c) : Shape(c), radius(c.radius) {};

    double getRadius() const;
    void setRadius(double);

    double getSquare() const override;

    void print() const override;
    void printInFile() const override;
};


#endif //OOPAD_2026_CIRCLE_H