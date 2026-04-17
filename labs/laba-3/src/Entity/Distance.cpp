// Distance.cpp
#include "Distance.h"

#include <sstream>

#include "../Controller/CheckInputThirdLab.h"

Distance::Distance(const int km, const int m) {
    kilometre = km;
    if (m >= 1000) {
        kilometre++;
        metre = m % 1000;
    } else {
        metre = m;
    }
}

Distance::Distance(const Distance &d) {
    kilometre = d.kilometre;
    metre = d.metre;
}

unsigned Distance::getKilometre() {
    return kilometre;
}

unsigned Distance::getMetre() {
    return metre;
}

void Distance::setKilometre(const unsigned km) {
    kilometre = km;
}

void Distance::setMetre(const unsigned m) {
    if (m >= 1000) {
        kilometre++;
        metre = m % 1000;
    } else {
        metre = m;
    }
}

bool Distance::operator> (Distance &d) {
    if (kilometre > d.kilometre) {
        return true;
    }

    if (kilometre == d.kilometre) {
        if (metre > d.metre) {
            return true;
        }
    }

    return false;
}

bool Distance::operator< (Distance &d) {
    if (kilometre < d.kilometre) {
        return true;
    }

    if (kilometre == d.kilometre) {
        if (metre < d.metre) {
            return true;
        }
    }

    return false;
}

Distance Distance::operator+ (Distance &d) {
    Distance new_dist;
    unsigned km, m;
    km = kilometre + d.kilometre;
    new_dist.setKilometre(km);

    m = metre + d.metre;
    new_dist.setMetre(m);

    return new_dist;
}

Distance Distance::operator- (Distance &d) {
    Distance new_dist;
    unsigned d1, d2, diff;
    d1 = kilometre * 1000 + metre;
    d2 = d.kilometre * 1000 + d.metre;

    unsigned km, m;
    diff = *this > d ? d1 - d2 : d2 - d1;
    km = diff / 1000;
    m = diff % 1000;

    new_dist.setKilometre(km);
    new_dist.setMetre(m);
    return new_dist;
}

bool Distance::operator== (Distance &d) {
    if (kilometre == d.kilometre && metre == d.metre) {
        return true;
    }
    return false;
}

std::istream& operator>> (std::istream &is, Distance &d) {
    unsigned km, m;
    std::cout << "Введите километры: ";
    km = CheckInput::inputNatural(is);
    d.setKilometre(km);

    std::cout << "Введите метры: ";
    m = CheckInput::inputNatural(is);
    d.setMetre(m);

    return is;
}

std::ostream& operator<< (std::ostream &os, const Distance &d) {
    std::stringstream ss;
    ss << d.kilometre << " км " << d.metre << " м" << std::endl;
    os << ss.str();
    return os;
}