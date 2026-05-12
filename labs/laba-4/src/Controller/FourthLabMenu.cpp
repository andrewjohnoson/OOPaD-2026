#include "FourthLabMenu.h"

#include "../../../../libs/TerminalController.h"
#include "RouteController.h"

void FourthLabMenu::doMenuAction(const int selected) {
    if (selected == menuCounter + 1) {
        std::cout << "Выход." << std::endl;
        exit(0);
    }

    if (selected == ADD_ROUTE) {
        RouteController::inputRoutes();
    }

    if (selected == CHANGE_ROUTE) {
        RouteController::changeRoute();
    }

    if (selected == OUTPUT_ROUTE) {
        RouteController::printRoutesList();
    }

    if (selected == DELETE_ROUTE) {
        RouteController::deleteRoute();
    }

    TerminalController::clearTerminal();
}
