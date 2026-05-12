#ifndef OOPAD_2026_GAME_H
#define OOPAD_2026_GAME_H

#include "HumanActivity.h"

class Game : HumanActivity {
    int playersMin, playersMax;
    string rules;
public:
    Game() : HumanActivity(), playersMin(1), playersMax(2), rules("") {}
    Game(const std::string&, bool, const std::string &, int, bool, const std::string &, int, int, const std::string &);
    Game(const Game& g) : HumanActivity(g), playersMin(g.playersMin), playersMax(g.playersMax), rules(g.rules) {}
    virtual ~Game() = default;

    int getPlayersMin() const;
    int getPlayersMax() const;
    std::string getRules() const;
    std::string getProcessName() const;
    Date getStartDate() const;
    int getParticipantCount() const;

    void setPlayersMin(int);
    void setPlayersMax(int);
    void setRules(const std::string&);

    bool isValidCount(int) const;

    void print() override;
};


#endif //OOPAD_2026_GAME_H