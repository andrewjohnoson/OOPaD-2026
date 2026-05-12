// Shape.cpp
#include "Shape.h"

#include <iomanip>
#include <iostream>
#include <fstream>

std::string Shape::getColor() const {
    return color;
}

std::string Shape::getType() const {
    return type;
}

int Shape::getId() const {
    return id;
}

void Shape::setId(const int ident) {
    id = ident;
}

void Shape::setColor(const std::string &c) {
    color = c;
}

void Shape::setType(const std::string &t) {
    type = t;
}

void Shape::print() const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "[" << type << "] id = " << id << " цвет=" << color
              << "  S=" << getSquare();
    if (getVolume() > 0) {
        std::cout << "  V=" << getVolume();
    }
    std::cout << std::endl;
}

void Shape::printInFile() const {
    std::fstream fout("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-5/files/shapes.txt", std::ios::app);

    fout << std::fixed << std::setprecision(4);
    fout << "[" << type << "] id = " << id << " цвет = " << color
              << "  S = " << getSquare();
    if (getVolume() > 0) {
        fout << "  V = " << getVolume();
    }
    fout << std::endl;
}
