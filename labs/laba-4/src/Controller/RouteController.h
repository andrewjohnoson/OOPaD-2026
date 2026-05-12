// RouteController.h
#ifndef OOPAD_2026_ROUTECONTROLLER_H
#define OOPAD_2026_ROUTECONTROLLER_H

#include "../Entity/Route.h"

#include <vector>

class RouteController {
    static std::vector <Route> routesList;
    static unsigned idCounter;
public:
    static void inputRoutes();
    static void changeRoute();
    static void deleteRoute();
    static unsigned getRouteIndex(unsigned);
    static void printRoutesList();
};


#endif //OOPAD_2026_ROUTECONTROLLER_H