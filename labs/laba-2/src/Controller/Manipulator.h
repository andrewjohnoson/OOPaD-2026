// Manipulator.h
#ifndef OOPAD_2026_MANIPULATOR_H
#define OOPAD_2026_MANIPULATOR_H

#include <iomanip>

class Manipulator {
public:
    static std::ostream& setForIntIterator(std::ostream&);
    static std::ostream& setForFloatIterator(std::ostream&);
    static std::ostream& setForNumbers(std::ostream&);
};

#endif //OOPAD_2026_MANIPULATOR_H