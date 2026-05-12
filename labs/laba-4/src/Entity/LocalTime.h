// LocalTime.h
#ifndef OOPAD_2026_LOCALTIME_H
#define OOPAD_2026_LOCALTIME_H

#include "DateTimeBase.h"
#include <string>

class LocalTime : public DateTimeBase {
public:
    LocalTime(unsigned = 0, unsigned = 0);
    unsigned getHour() const;
    unsigned getMinute() const;
    void setHour(unsigned);
    void setMinute(unsigned);
    std::string getTimeOfDay() const;

    friend std::ostream& operator<< (std::ostream &, const LocalTime &);
};


#endif //OOPAD_2026_LOCALTIME_H