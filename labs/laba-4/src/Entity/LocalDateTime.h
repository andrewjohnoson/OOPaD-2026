#ifndef OOPAD_2026_LOCALDATETIME_H
#define OOPAD_2026_LOCALDATETIME_H

#include "LocalDate.h"
#include "LocalTime.h"

#include <string>

class LocalDateTime {
protected:
    LocalDate localDate;
    LocalTime localTime;
public:
    LocalDateTime(int = 0, int = 0, int = 0, int = 0, int = 0);
    unsigned getHour() const;
    unsigned getMinute() const;
    unsigned getDay() const;
    unsigned getMonth() const;
    unsigned getYear() const;
    void setHour(int);
    void setMinute(int);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    std::string getSeason() const;
    std::string getTimeOfDay() const;
};


#endif //OOPAD_2026_LOCALDATETIME_H