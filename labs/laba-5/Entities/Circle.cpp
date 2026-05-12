// Circle.cpp
#include "Circle.h"

#include <iostream>
#include <iomanip>
#include <fstream>

Circle::Circle(const double r) {
    radius = r;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(const double r) {
    radius = r;
}

double Circle::getSquare() const {
    return PI * radius * radius;
}

void Circle::print() const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "[Круг] id = " << id << " радиус = " << radius
                  << "  цвет = " << color
                  << "  S = " << getSquare() << std::endl;
}

void Circle::printInFile() const {
    std::fstream fout("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-5/files/shapes.txt", std::ios::app);

    fout << std::fixed << std::setprecision(4);
    fout << "[Круг] id = " << id << " радиус = " << radius
                  << "  цвет = " << color
                  << "  S = " << getSquare() << std::endl;
    fout << std::endl;
}