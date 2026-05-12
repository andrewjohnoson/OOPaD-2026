#ifndef KR_OAIP_DATE_H
#define KR_OAIP_DATE_H

#include <string>

class Date {
    unsigned day;
    unsigned month;
    int year;
public:
    Date();
    Date(std::string);
    std::string getDate() const;
    void setDate(std::string);
    void setCurrentDate();
    static bool isLeapYear(int);
    void subtractDays(int);
    static bool isValidFormat(std::string);

    friend std::ostream& operator<< (std::ostream &os, const Date &d);
    bool operator< (const Date &) const;
    bool operator> (const Date &) const;
};


#endif //KR_OAIP_DATE_H