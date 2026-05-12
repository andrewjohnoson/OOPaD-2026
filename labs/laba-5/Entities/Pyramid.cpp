// Pyramid.cpp
#include "Pyramid.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

Pyramid::Pyramid(const double s, const double h) {
    side = s > 0.0 ? s : 0.0;
    height = h > 0.0 ? h : 0.0;
}

double Pyramid::getHeight() const {
    return height;
}

double Pyramid::getSide() const {
    return side;
}

void Pyramid::setSide(const double s) {
    side = s;
}

void Pyramid::setHeight(const double h) {
    height = h;
}

double Pyramid::getSquare() const {
    return side * side + 2.0 * side * sqrt(height * height + side * side / 4.0);
}

double Pyramid::getVolume() const {
    return side * side * height / 3.0;
}

void Pyramid::print() const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "[Пирамида] id = " << id << " сторона основания = " << side << " высота = " << height
                  << "  цвет = " << color
                  << "  S = " << getSquare()
                  << "  V = " << getVolume() << std::endl;
}

void Pyramid::printInFile() const {
    std::fstream fout("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-5/files/shapes.txt", std::ios::app);

    fout << std::fixed << std::setprecision(4);
    fout << "[Пирамида] id = " << id << " сторона основания = " << side << " высота = " << height
                  << "  цвет =" << color
                  << "  S = " << getSquare()
                  << "  V = " << getVolume() << std::endl;
    fout << std::endl;
}