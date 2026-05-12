// Square.cpp
#include "Square.h"

#include <iostream>
#include <iomanip>
#include <fstream>

void Square::setSide(const double s) {
    side = s;
}

double Square::getSide() const {
    return side;
}

double Square::getSquare() const {
    return side * side;
}

void Square::print() const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "[Квадрат] id = " << id << " сторона = " << side
                  << "  цвет = " << color
                  << "  S = " << getSquare() << std::endl;
}

void Square::printInFile() const {
    std::fstream fout("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-5/files/shapes.txt", std::ios::app);

    fout << std::fixed << std::setprecision(4);
    fout << "[Квадрат] id = " << id << " сторона = " << side
                  << "  цвет = " << color
                  << "  S = " << getSquare() << std::endl;
    fout << std::endl;
}
