// CheckInput.h
#ifndef OOPAD_2026_CHECKINPUT_H
#define OOPAD_2026_CHECKINPUT_H

class CheckInput {
public:
    static int inputNatural();
    static int inputIndex();
    static int inputInt();
    static double inputDouble();
    static unsigned inputUnsigned();
    static unsigned inputYear();
    static unsigned inputMonth();
    static unsigned inputDay(unsigned, unsigned);
    static unsigned inputHour();
    static unsigned inputMinute();
    static bool isLeapYear(unsigned);
};


#endif //OOPAD_2026_CHECKINPUT_H