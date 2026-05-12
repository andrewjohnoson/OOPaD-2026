// Triangle.cpp
#include "Triangle.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

Triangle::Triangle(const double a1, const double b1, const double c1) : Shape("жёлтый", "треугольник") {
    a = a1 > 0.0 ? a1 : 0.0;
    b = b1 > 0.0 ? b1 : 0.0;
    c = c1 > 0.0 ? c1 : 0.0;

    updateKind();
}

void Triangle::updateKind() {
    if (abs(a - b) < 1e-9 && abs(c - a) < 1e-9 && abs(b - c) < 1e-9) {
        kind = "равносторонний";
    }

    if (abs(a - b) < 1e-9 || abs(c - a) < 1e-9 || abs(b - c) < 1e-9) {
        kind = "равнобедренный";
    }

    if (std::abs(a*a + b*b - c*c) < 1e-9 ||
                 std::abs(b*b + c*c - a*a) < 1e-9 ||
                 std::abs(a*a + c*c - b*b) < 1e-9)
        kind = "прямоугольный";
    else
        kind = "с разными длинами сторон";

}

std::string Triangle::getKind() const {
    return kind;
}

void Triangle::setKind(const std::string& k) {
    kind = k;
}

double Triangle::getA() const {
    return a;
}

double Triangle::getB() const {
    return b;
}

double Triangle::getC() const {
    return c;
}

void Triangle::setA(const double a1) {
    a = a1 > 0.0 ? a1 : 0.0;
    updateKind();
}

void Triangle::setB(const double b1) {
    a = b1 > 0.0 ? b1 : 0.0;
    updateKind();
}

void Triangle::setC(const double c1) {
    a = c1 > 0.0 ? c1 : 0.0;
    updateKind();
}

double Triangle::getSquare() const {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::print() const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "[Треугольник] id = " << id << " a = " << a << " b = " << b << " c = " << c
                  << "  вид = " << kind
                  << "  цвет = " << color
                  << "  S = " << getSquare() << std::endl;
}

void Triangle::printInFile() const {
    std::fstream fout("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-5/files/shapes.txt", std::ios::app);

    fout << std::fixed << std::setprecision(4);
    fout << "[Треугольник] id = " << id << " a = " << a << " b = " << b << " c = " << c
                  << "  вид = " << kind
                  << "  цвет = " << color
                  << "  S = " << getSquare() << std::endl;
    fout << std::endl;
}