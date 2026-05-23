// CompetitiveSport.h
#ifndef OOPAD_2026_COMPETITIVESPORT_H
#define OOPAD_2026_COMPETITIVESPORT_H

#include <string>
#include <iostream>

class CompetitiveSport {
protected:
    std::string federation;
    int minAge;
    bool isOlympic;
public:
    CompetitiveSport() : federation(""), minAge(0), isOlympic(false) {}
    CompetitiveSport(const std::string&, int, bool);
    CompetitiveSport(const CompetitiveSport& c) : federation(c.federation), minAge(c.minAge), isOlympic(c.isOlympic) {}
    virtual ~CompetitiveSport() = default;

    std::string getFederation() const;
    int getMinAge() const;
    bool getIsOlympic() const;

    void setFederation(const std::string &);
    void setMinAge(int);
    void setIsOlympic(bool);

    bool isEligible(int) const;

    void print();
};


#endif //OOPAD_2026_COMPETITIVESPORT_H