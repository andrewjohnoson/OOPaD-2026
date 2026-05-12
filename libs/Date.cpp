#include "Date.h"

#include <chrono>
#include <iostream>
#include <sstream>

Date::Date() {
    auto now = std::chrono::system_clock::now();
    auto today = std::chrono::floor<std::chrono::days>(now);
    auto ymd = std::chrono::year_month_day(today);

    this->day = static_cast<unsigned> (ymd.day());
    this->month = static_cast<unsigned> (ymd.month());
    this->year = static_cast<int> (ymd.year());
}

Date::Date(std::string dateSource) {
    if (dateSource.empty() || dateSource.length() != 10 || dateSource.find('-') == dateSource.rfind('-')) {
        setCurrentDate();
        return;
    }

    if (dateSource[4] != '-' || dateSource[7] != '-') {
        setCurrentDate();
        return;
    }

    size_t i = dateSource.find('-');
    const int y = std::stoi(dateSource.substr(0, i));
    if (y > 2100 || y < 200) {
        setCurrentDate();
        return;
    }
    year = y;


    dateSource.erase(0, i + 1);
    i = dateSource.find('-');
    const unsigned m = std::stoul(dateSource.substr(0, i));
    month = m;
    if (m < 1 || m > 12) {
        setCurrentDate();
        return;
    }

    dateSource.erase(0, i + 1);
    const unsigned d = std::stoul(dateSource.substr(0, i));
    if (isLeapYear(y) && m == 2) {
        if (d > 29 || d < 1) {
            setCurrentDate();
            return;
        }
    } else if (m == 2) {
        if (d > 28 || d < 1) {
            setCurrentDate();
            return;
        }
    }

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 9 || m == 11 || m == 12) {
        if (d > 31 || d < 1) {
            setCurrentDate();
            return;
        }
    } else {
        if (d > 30 || d < 1) {
            setCurrentDate();
            return;
        }
    }

    day = d;
}

void Date::setCurrentDate() {
    auto now = std::chrono::system_clock::now();
    auto today = std::chrono::floor<std::chrono::days>(now);
    auto ymd = std::chrono::year_month_day(today);

    this->day = (unsigned) ymd.day();
    this->month = (unsigned) ymd.month();
    this->year = (int) ymd.year();
}

void Date::setDate(std::string dateSource) {
    if (dateSource.empty() || dateSource.length() != 10 || dateSource.find('-') == dateSource.rfind('-')) {
        setCurrentDate();
        return;
    }

    if (dateSource[4] != '-' || dateSource[7] != '-') {
        setCurrentDate();
        return;
    }

    size_t i = dateSource.find('-');
    const int y = std::stoi(dateSource.substr(0, i));
    if (y > 2100 || y < 200) {
        setCurrentDate();
        return;
    }
    year = y;


    dateSource.erase(0, i + 1);
    i = dateSource.find('-');
    const unsigned m = std::stoul(dateSource.substr(0, i));
    month = m;
    if (m < 1 || m > 12) {
        setCurrentDate();
        return;
    }

    dateSource.erase(0, i + 1);
    const unsigned d = std::stoul(dateSource.substr(0, i));
    if (isLeapYear(y) && m == 2) {
        if (d > 29 || d < 1) {
            setCurrentDate();
            return;
        }
    } else if (m == 2) {
        if (d > 28 || d < 1) {
            setCurrentDate();
            return;
        }
    }

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 9 || m == 11 || m == 12) {
        if (d > 31 || d < 1) {
            setCurrentDate();
            return;
        }
    } else {
        if (d > 30 || d < 1) {
            setCurrentDate();
            return;
        }
    }

    day = d;
}

std::string Date::getDate() const {
    std::stringstream ss;
    ss << year << "-";

    if (month < 10) {
        ss << "0" << month << "-";
    } else {
        ss << month << "-";
    }

    if (day < 10) {
        ss << "0" << day;
    } else {
        ss << day;
    }
    return ss.str();
}

bool Date::isLeapYear(const int y) {
    if (y % 4 == 0 || y % 400 == 0) {
        return true;
    }

    if (y % 100 == 0) {
        return false;
    }

    return false;
}

bool Date::isValidFormat(std::string dateSource) {
    if (dateSource.empty() || dateSource.length() != 10 || dateSource.find('-') == dateSource.rfind('-')) {
        return false;
    }

    if (dateSource[4] != '-' || dateSource[7] != '-') {
        return false;
    }

    const int y = std::stoi(dateSource.substr(0, 4));
    if (y > 2100 || y < 200) {
        return false;
    }

    dateSource.erase(0, 5);
    const unsigned m = std::stoul(dateSource.substr(0, 2));
    if (m < 1 || m > 12) {
        return false;
    }

    dateSource.erase(0, 3);
    const unsigned d = std::stoul(dateSource.substr(0, 2));

    if (isLeapYear(y) && m == 2) {
        if (d > 29 || d < 1) {
            return false;
        }
    } else if (m == 2) {
        if (d > 28 || d < 1) {
            return false;
        }
    }

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 9 || m == 11 || m == 12) {
        if (d > 31 || d < 1) {
            return false;
        }
    } else {
        if (d > 30 || d < 1) {
            return false;
        }
    }

    return true;
}

std::ostream& operator<< (std::ostream &os, const Date &d) {
    std::stringstream ss;
    ss << d.year << "-";

    if (d.month < 10) {
        ss << "0" << d.month << "-";
    } else {
        ss << d.month << "-";
    }

    if (d.day < 10) {
        ss << "0" << d.day;
    } else {
        ss << d.day;
    }
    os << ss.str();
    return os;
}

void Date::subtractDays(const int days) {
    std::chrono::year_month_day ymd{std::chrono::year{this->year},
                    std::chrono::month{this->month}, std::chrono::day{this->day}};
    std::chrono::sys_days current = std::chrono::sys_days{ymd};

    std::chrono::sys_days result = current - std::chrono::days{days};

    std::chrono::year_month_day newYmd{result};

    day = static_cast<unsigned>(newYmd.day());
    month = static_cast<unsigned>(newYmd.month());
    year = static_cast<int>(newYmd.year());
}

bool Date::operator< (const Date &d) const {
    if (year != d.year) {
        return year < d.year;
    }

    if (month != d.month) {
        return month < d.month;
    }

    return day < d.day;
}

bool Date::operator> (const Date &d) const {
    if (year != d.year) {
        return year > d.year;
    }

    if (month != d.month) {
        return month > d.month;
    }

    return day > d.day;
}