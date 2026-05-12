// Triangle.h
#ifndef OOPAD_2026_TRIANGLE_H
#define OOPAD_2026_TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
    double a, b, c;
    std::string kind;
    void updateKind();
public:
    Triangle() : Shape("жёлтый", "треугольник"), a(0.0), b(0.0), c(0.0) { updateKind(); }
    Triangle(double, double, double);
    Triangle(const Triangle& t) : Shape(t), a(t.a), b(t.b), c(t.c), kind(t.kind) {}

    double getA() const;
    double getB() const;
    double getC() const;
    void setA(double);
    void setB(double);
    void setC(double);
    std::string getKind() const;
    void setKind(const std::string &);

    double getSquare() const override;

    void print() const override;
    void printInFile() const;
};


#endif //OOPAD_2026_TRIANGLE_H