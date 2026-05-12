// Square.h
#ifndef OOPAD_2026_SQUARE_H
#define OOPAD_2026_SQUARE_H

#include "Shape.h"

class Square : public Shape {
protected:
    double side;
public:
    Square() : Shape("красный", "квадрат"), side(0.0) {}
    Square(const Square& s) : Shape(s), side(s.side) {}

    void setSide(double);
    double getSide() const;
    double getSquare() const override;

    void print() const override;
    void printInFile() const override;
};


#endif //OOPAD_2026_SQUARE_H