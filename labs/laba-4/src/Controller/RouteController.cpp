// RouteController.cpp
#include "RouteController.h"
#include "../../../../libs/CheckInput.h"
#include "../../../../libs/TerminalController.h"

#include <iostream>

std::vector <Route> RouteController::routesList;
unsigned RouteController::idCounter = 1;

void RouteController::inputRoutes() {
    std::cout << "Сколько записей хотите добавить (введите -1 для выхода): ";
    const int amount = CheckInput::inputIndex();
    if (amount == -1) {
        return;
    }
    std::cout << std::endl;

    for (int i = 0; i < amount; i++) {
        std::cout << "Маршрут №" << idCounter << std::endl;
        Route route;
        std::cin >> route;
        route.setId(idCounter++);
        routesList.push_back(route);
        std::cout << std::endl;
    }

    std::cout << "Введено" << std::endl
            << "Нажмите клавишу, чтобы продолжить." << std::flush;
    TerminalController::getch();
}

void RouteController::changeRoute() {
    if (routesList.empty()) {
        std::cout << "Массив пуст." << std::endl
                << "Нажмите клавишу, чтобы продолжить." << std::flush;
        TerminalController::getch();
        return;
    }

    while (true) {
        std::cout << "Список доступных маршрутов: ";
        for (const Route &route : routesList) {
            std::cout << route.getId() << " ";
        }
        std::cout << std::endl;
        std::cout << "Выберите идентификатор маршрута (-1 для выхода): ";
        unsigned ident = CheckInput::inputIndex();
        if (ident == -1) {
            std::cout << "Нажмите клавишу, чтобы продолжить." << std::flush;
            TerminalController::getch();
            return;
        }

        unsigned index = getRouteIndex(ident);
        if (index == -1) {
            std::cout << "Маршрута с таким идентификатором не существует." << std::endl;
            continue;
        }

        std::cin >> routesList[index];

        std::cout << "Изменено." << std::endl << std::endl;
    }
}

void RouteController::deleteRoute() {
    if (routesList.empty()) {
        std::cout << "Массив пуст." << std::endl
                << "Нажмите клавишу, чтобы продолжить." << std::flush;
        TerminalController::getch();
        return;
    }

    while (true) {
        std::cout << "Список доступных маршрутов: ";
        for (const Route &route : routesList) {
            std::cout << route.getId() << " ";
        }
        std::cout << std::endl;
        std::cout << "Выберите идентификатор маршрута (-1 для выхода): ";
        unsigned ident = CheckInput::inputIndex();
        if (ident == -1) {
            std::cout << "Нажмите клавишу, чтобы продолжить." << std::flush;
            TerminalController::getch();
            return;
        }

        unsigned index = getRouteIndex(ident);
        if (index == -1) {
            std::cout << "Маршрута с таким идентификатором не существует." << std::endl;
            continue;
        }
        routesList.erase(routesList.begin() + index);

        std::cout << "Удалено." << std::endl << std::endl;
    }
}

unsigned RouteController::getRouteIndex(unsigned ident) {
    unsigned i = 0;
    for (i = 0; i < routesList.size(); i++) {
        if (routesList[i].getId() == ident) {
            return i;
        }
    }
    if (i == routesList.size() || i == 0) {
        return -1;
    }
}

void RouteController::printRoutesList() {
    if (routesList.empty()) {
        std::cout << "Массив пуст." << std::endl
                << "Нажмите клавишу, чтобы продолжить." << std::flush;
        TerminalController::getch();
        return;
    }

    std::cout << "Список маршрутов " << std::endl
            << "================" << std::endl << std::endl;
    for (const Route &route : routesList) {
        std::cout << route << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Выведено." << std::endl
            << "Нажмите клавишу, чтобы продолжить." << std::flush;
    TerminalController::getch();

}
