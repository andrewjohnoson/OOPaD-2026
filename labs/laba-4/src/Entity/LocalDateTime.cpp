//LocalDateTime.cpp
#include "LocalDateTime.h"

#include <sstream>

LocalDateTime::LocalDateTime(unsigned y, unsigned mth, unsigned d, unsigned h, unsigned mt) {
    localDate.setYear(y);
    localDate.setMonth(mth);
    localDate.setDay(d);
    localTime.setHour(h);
    localTime.setMinute(mt);
}

unsigned LocalDateTime::getYear() const {
    return localDate.getYear();
}

unsigned LocalDateTime::getMonth() const {
    return localDate.getMonth();
}

unsigned LocalDateTime::getDay() const {
    return localDate.getDay();
}

unsigned LocalDateTime::getHour() const {
    return localTime.getHour();
}

unsigned LocalDateTime::getMinute() const {
    return localTime.getMinute();
}

std::string LocalDateTime::getSeason() const {
    return localDate.getSeason();
}

std::string LocalDateTime::getTimeOfDay() const {
    return localTime.getTimeOfDay();
}

void LocalDateTime::setYear(unsigned year) {
    localDate.setYear(year);
}

void LocalDateTime::setMonth(unsigned month) {
    localDate.setMonth(month);
}

void LocalDateTime::setDay(unsigned day) {
    localDate.setDay(day);
}

void LocalDateTime::setHour(unsigned hour) {
    localTime.setHour(hour);
}

void LocalDateTime::setMinute(unsigned minute) {
    localTime.setMinute(minute);
}

std::ostream& operator<< (std::ostream& os, const LocalDateTime& dateTime) {
    std::stringstream ss;

    ss << dateTime.localDate << " " << dateTime.localTime;

    os << ss.str();
    return os;
}