// Organisation.h
#ifndef OOPAD_2026_ORGANISATION_H
#define OOPAD_2026_ORGANISATION_H

#include <string>
#include <iostream>

class Organisation {
    std::string orgName;
    std::string address;
public:
    Organisation() : orgName("не задано"), address("не задан") {}

    Organisation(const std::string& orgName, const std::string& address)
        : orgName(orgName), address(address) {}

    Organisation(const Organisation& o)
        : orgName(o.orgName), address(o.address) {}

    virtual ~Organisation() = default;

    std::string getOrgName() const;
    std::string getAddress() const;

    void setOrgName(const std::string &);
    void setAddress(const std::string&);

    virtual void print() const;
};


#endif //OOPAD_2026_ORGANISATION_H