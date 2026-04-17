#ifndef OOPAD_2026_LOCALDATE_H
#define OOPAD_2026_LOCALDATE_H

#include "DateTimeBase.h"

#include <string>

class LocalDate : public DateTimeBase {
public:
    LocalDate(unsigned = 0, unsigned = 0, unsigned = 0);
    unsigned getDay() const;
    unsigned getMonth() const;
    unsigned getYear() const;
    void setDay(unsigned);
    void setMonth(unsigned);
    void setYear(unsigned);
    std::string getSeason() const;
    static bool isLeapYear(unsigned);
};


#endif //OOPAD_2026_LOCALDATE_H