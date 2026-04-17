// Manipulator.cpp
#include "Manipulator.h"

#include <iomanip>
#include <iostream>

std::ostream& Manipulator::setForIntIterator(std::ostream& stream) {
    stream.setf(std::ios::left);
    stream << std::setw(4);
    return stream;
}

std::ostream& Manipulator::setForFloatIterator(std::ostream& stream) {
    stream.setf(std::ios::left);
    stream << std::setw(6);
    return stream;
}

std::ostream& Manipulator::setForNumbers(std::ostream& stream) {
    stream.setf(std::ios::left);
    stream << std::setw(8) << std::setprecision(5);
    return stream;
}

