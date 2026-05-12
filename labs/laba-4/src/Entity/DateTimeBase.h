// DateTimeBase.h
#ifndef OOPAD_2026_DATETIMEBASE_H
#define OOPAD_2026_DATETIMEBASE_H

class DateTimeBase {
protected:
    unsigned year;
    unsigned month;
    unsigned day;
    unsigned hour;
    unsigned minute;
public:
    DateTimeBase(unsigned = 0, unsigned = 0, unsigned = 0, unsigned = 0, unsigned = 0);
};


#endif //OOPAD_2026_DATETIMEBASE_H