// Route.cpp
#include "Route.h"

#include "../../../../libs/CheckInput.h"

Route::Route(unsigned ident, std::string titleInput, LocalDateTime arrivalInput, LocalDateTime departureInput) {
    id = ident;
    title = titleInput;
    arrival = arrivalInput;
    departure = departureInput;
}

unsigned Route::getId() const {
    return id;
}

std::string Route::getTitle() const {
    return title;
}

LocalDateTime Route::getArrival() const {
    return arrival;
}

LocalDateTime Route::getDeparture() const {
    return departure;
}

void Route::setId(unsigned ident) {
    id = ident;
}

void Route::setTitle(const std::string &t) {
    title = t;
}

void Route::setArrival(const LocalDateTime &arr) {
    arrival = arr;
}

void Route::setDeparture(const LocalDateTime &depart) {
    departure = depart;
}

std::istream& operator>> (std::istream &is, Route &route) {
    std::cout << "Введите название маршрута: ";
    std::getline(is, route.title);

    std::cout << "Введите дату и время отправления" << std::endl
            << "Год: " << std::flush;
    unsigned year = CheckInput::inputYear();
    route.departure.setYear(year);

    std::cout << "Месяц: ";
    unsigned mth = CheckInput::inputMonth();
    route.departure.setMonth(mth);

    std::cout << "День: ";
    unsigned day = CheckInput::inputDay(year, mth);
    route.departure.setDay(day);

    std::cout << "Час: ";
    unsigned hour = CheckInput::inputHour();
    route.departure.setHour(hour);

    std::cout << "Минута: ";
    unsigned minute = CheckInput::inputMinute();
    route.departure.setMinute(minute);

    std::cout << std::endl;

    std::cout << "Введите дату и время прибытия" << std::endl
            << "Год: ";
    while (true) {
        year = CheckInput::inputYear();
        if (year < route.departure.getYear() || (year == route.departure.getYear() && route.departure.getMonth() == 12 && route.departure.getDay() == 31)) {
            std::cout << "Некорректно введённый год. Повторите ввод: ";
        } else {
            break;
        }
    }
    route.arrival.setYear(year);

    std::cout << "Месяц: ";
    while (true) {
        mth = CheckInput::inputMonth();
        if (mth < route.departure.getMonth() && route.departure.getYear() == year) {
            std::cout << "Некорректно введённый месяц. Повторите ввод: ";
        } else {
            break;
        }
    }
    route.arrival.setMonth(mth);

    std::cout << "День: ";
    while (true) {
        day = CheckInput::inputDay(year, mth);
        if (day < route.departure.getDay() && route.departure.getMonth() == mth) {
            std::cout << "Некорректно введённый день. Повторите ввод: ";
        } else {
            break;
        }
    }
    route.arrival.setDay(day);

    std::cout << "Час: ";
    while (true) {
        hour = CheckInput::inputHour();
        if (hour < route.departure.getHour() && route.departure.getDay() == day) {
            std::cout << "Некорректно введённый час. Повторите ввод: ";
        } else {
            break;
        }
    }
    route.arrival.setHour(hour);

    std::cout << "Минута: ";
    while (true) {
        minute = CheckInput::inputMinute();
        if (minute < route.departure.getMinute() && route.departure.getHour() == hour) {
            std::cout << "Некорректно введённая минута. Повторите ввод: ";
        } else {
            break;
        }
    }
    route.arrival.setMinute(minute);

    return is;
}

std::ostream& operator<< (std::ostream &os, const Route &route) {
    os << "Идентификатор маршрута: " << route.getId() << std::endl
        << "Название маршрута: \"" << route.getTitle() << "\"" << std::endl
        << "Время и дата отправления: " << route.getArrival() << std::endl
        << "Время и дата прибытия: " << route.getDeparture();
    return os;
}