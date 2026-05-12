// LocalTime.cpp
#include "LocalTime.h"

#include <sstream>

LocalTime::LocalTime(const unsigned h, const unsigned m) {
    setHour(h);
    setMinute(m);
}

void LocalTime::setHour(const unsigned h) {
    if (h > 23) {
        hour = 0;
        return;
    }
    hour = h;
}

void LocalTime::setMinute(const unsigned m) {
    if (m > 59) {
        minute = 0;
        return;
    }

    minute = m;
}

unsigned LocalTime::getHour() const {
    return hour;
}

unsigned LocalTime::getMinute() const {
    return minute;
}

std::string LocalTime::getTimeOfDay() const {
    if (hour == 23 || hour >= 0 && hour < 4) {
        return "Ночь";
    }

    if (hour >= 4 && hour <= 10) {
        return "Утро";
    }

    if (hour >= 11 & hour <= 16) {
        return "День";
    }

    return "Вечер";
}

std::ostream& operator<< (std::ostream& os, const LocalTime& time) {
    std::stringstream ss;

    if (time.hour < 10) {
        ss << "0" << time.hour << ":";
    } else {
        ss << time.hour << ":";
    }

    if (time.minute < 10) {
        ss << "0" << time.minute;
    } else {
        ss << time.minute;
    }

    os << ss.str() << " " << time.getTimeOfDay();
    return os;
}