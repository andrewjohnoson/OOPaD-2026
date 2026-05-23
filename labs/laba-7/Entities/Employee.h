// Employee.h
#ifndef OOPAD_2026_EMPLOYEE_H
#define OOPAD_2026_EMPLOYEE_H

#include <string>

#include "Subscription.h"

class Employee {
    int id;
    std::string fullName;
    std::string position;
    Subscription* currentSub;
public:
    Employee() : id(0), fullName("Unknown"), position("Unknown"), currentSub(nullptr) {}

    Employee(int id, const std::string& fullName,
             const std::string& position)
        : id(id), fullName(fullName), position(position),
         currentSub(nullptr) {}

    Employee(const Employee& other)
        : id(other.id), fullName(other.fullName), position(other.position),
           currentSub(nullptr) {}

    ~Employee();

    int getId() const;
    std::string getFullName() const;
    std::string getPosition() const;
    Subscription* getCurrentSub() const;

    void setId(int);
    void setFullName(const std::string &);
    void setPosition(const std::string &);

    void takeSubscription(Subscription *);
    void releaseSubscription();
    void print() const;
};


#endif //OOPAD_2026_EMPLOYEE_H