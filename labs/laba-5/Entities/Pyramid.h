// Pyramid.h
#ifndef OOPAD_2026_PYRAMID_H
#define OOPAD_2026_PYRAMID_H

#include "Shape.h"

class Pyramid : public Shape {
    double side, height ;
public:
    Pyramid() : Shape("синий", "пирамида"), side(0.0), height(0.0) {}
    Pyramid(double, double);
    Pyramid(const Pyramid& p) : Shape(p), side(p.side), height(p.height) {};

    void setSide(double);
    double getSide() const;
    void setHeight(double);
    double getHeight() const;

    double getSquare() const override;
    double getVolume() const override;

    void print() const override;
    void printInFile() const override;

};


#endif //OOPAD_2026_PYRAMID_H