// Distance.h
#ifndef OOPAD_2026_DISTANCE_H
#define OOPAD_2026_DISTANCE_H

#include <iostream>

class Distance {
    unsigned kilometre;
    unsigned metre;
public:
    Distance(int = 0, int = 0);
    Distance(const Distance &);
    unsigned getKilometre();
    unsigned getMetre();
    void setKilometre(unsigned);
    void setMetre(unsigned);

    Distance operator+ (Distance &);
    Distance operator- (Distance &);
    bool operator== (Distance &);
    bool operator< (Distance &);
    bool operator> (Distance &);


    friend std::istream& operator>> (std::istream &is, Distance &d);
    friend std::ostream& operator<< (std::ostream &, const Distance &);
};


#endif //OOPAD_2026_DISTANCE_H