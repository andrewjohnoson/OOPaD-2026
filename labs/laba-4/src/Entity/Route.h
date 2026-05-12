// Route.h
#ifndef OOPAD_2026_ROUTE_H
#define OOPAD_2026_ROUTE_H

#include "LocalDateTime.h"

#include <string>
#include <iostream>

class Route {
    unsigned id;
    std::string title;
    LocalDateTime departure;
    LocalDateTime arrival;
public:
    Route(unsigned = 0, std::string = "", LocalDateTime = LocalDateTime(), LocalDateTime = LocalDateTime());
    unsigned getId() const;
    std::string getTitle() const;
    LocalDateTime getDeparture() const;
    LocalDateTime getArrival() const;
    void setId(unsigned id);
    void setTitle(const std::string &);
    void setDeparture(const LocalDateTime &);
    void setArrival(const LocalDateTime &);

    friend std::istream& operator>> (std::istream&, Route &);
    friend std::ostream& operator<< (std::ostream&, const Route &);
};


#endif //OOPAD_2026_ROUTE_H