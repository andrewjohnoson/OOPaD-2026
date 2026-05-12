// LocalDateTime.h
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
    LocalDateTime(unsigned = 0, unsigned = 0, unsigned = 0, unsigned = 0, unsigned = 0);
    unsigned getHour() const;
    unsigned getMinute() const;
    unsigned getDay() const;
    unsigned getMonth() const;
    unsigned getYear() const;
    void setHour(unsigned);
    void setMinute(unsigned);
    void setDay(unsigned);
    void setMonth(unsigned);
    void setYear(unsigned);
    std::string getSeason() const;
    std::string getTimeOfDay() const;

    friend std::ostream& operator<< (std::ostream &, const LocalDateTime &);
};


#endif //OOPAD_2026_LOCALDATETIME_H