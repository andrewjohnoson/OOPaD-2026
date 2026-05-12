//LocalDate.cpp
#include "LocalDate.h"

#include <sstream>

LocalDate::LocalDate(const unsigned y, const unsigned m, const unsigned d) {
    setYear(y);
    setMonth(m);
    setDay(d);
}

void LocalDate::setYear(const unsigned y) {
    if (y < 2000 || y > 2300) {
        year = 0;
        return;
    }

    year = y;
}

void LocalDate::setMonth(const unsigned m) {
    if (m > 12 || m == 0) {
        month = 0;
        return;
    }

    month = m;
}

void LocalDate::setDay(unsigned d) {
    if (year == 0 || month == 0) {
        day = 0;
        return;
    }

    if (month == 2) {
        if (isLeapYear(year) && d > 29) {
            day = 0;
            return;
        }
        if (d > 28) {
            day = 0;
            return;
        }
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (d > 31) {
            day = 0;
            return;
        }
    } else {
        if (d > 30) {
            day = 0;
            return;
        }
    }

    day = d;
}

bool LocalDate::isLeapYear(const unsigned y) {
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        return true;
    }
    return false;
}

unsigned LocalDate::getYear() const {
    return year;
}

unsigned LocalDate::getMonth() const {
    return month;
}

unsigned LocalDate::getDay() const {
    return day;
}

std::string LocalDate::getSeason() const {
    if (month == 12 || month == 1 || month == 2) {
        return "Зима";
    }

    if (month >= 3 && month <= 5) {
        return "Весна";
    }

    if (month >= 6 && month <= 8) {
        return "Лето";
    }

    return "Осень";
}

std::ostream& operator<< (std::ostream& os, const LocalDate& date) {
    std::stringstream ss;
    ss << date.year << "-";

    if (date.month < 10) {
        ss << "0" << date.month << "-";
    } else {
        ss << date.month << "-";
    }

    if (date.day < 10) {
        ss << "0" << date.day;
    } else {
        ss << date.day;
    }

    os << ss.str() << " " << date.getSeason();
    return os;
}