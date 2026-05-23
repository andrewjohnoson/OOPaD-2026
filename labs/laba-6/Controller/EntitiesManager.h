//EntitiesManager.h
#ifndef OOPAD_2026_ENTITIESMANAGER_H
#define OOPAD_2026_ENTITIESMANAGER_H

#include <vector>
#include <string>

#include "../Entities/Process.h"
#include "../Entities/CompetitiveSport.h"
#include "../Entities/HumanActivity.h"
#include "../Entities/Game.h"
#include "../Entities/Esports.h"

class EntitiesManager {
    enum entity {
        PROCESS = 1, HUMAN_ACTIVITY, GAME, ESPORTS, COMPETITIVE_SPORT
    };
    static std::vector <Process> processes;
    static std::vector <CompetitiveSport> competitiveSports;
    static std::vector <HumanActivity> humanActivities;
    static std::vector <Game> games;
    static std::vector <Esports> esports;
    static std::string PATH;

public:
    static void addEntity(int);
    static void showEntities(int);

};


#endif //OOPAD_2026_ENTITIESMANAGER_H