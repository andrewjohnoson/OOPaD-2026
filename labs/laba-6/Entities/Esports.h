#ifndef OOPAD_2026_ESPORTS_H
#define OOPAD_2026_ESPORTS_H

#include "CompetitiveSport.h"
#include "Game.h"

class Esports : public Game, CompetitiveSport {
    string gameTitle;
    string platform;
    double prizePool;
public:
    Esports() : Game(), CompetitiveSport(), gameTitle(""), platform(""), prizePool(0) {}
    Esports(const std::string&, bool, const std::string &, int, bool, const std::string &,
        int, int, const std::string &, const std::string &,
         const std::string &, double, const std::string &, int, bool);

    Esports(const Esports &e) : Game(e), CompetitiveSport(e), gameTitle(e.gameTitle), platform(e.platform), prizePool(e.prizePool) {}
    virtual ~Esports() = default;

    bool isEligible(int) const;

    std::string getGameTitle() const;
    std::string getPlatform()  const;
    double getPrizePool() const;

    void setGameTitle(const std::string&);
    void setPlatform(const std::string&);
    void setPrizePool(double);

    void matchReport() const;
    void print() override;

};


#endif //OOPAD_2026_ESPORTS_H