#include "SixthLabMenu.h"

#include "EntitiesManager.h"

#include <iostream>

void SixthLabMenu::doMenuAction(int selected) {
    if (selected == menuCounter + 1) {
        std::cout << "Выход." << std::endl;
        exit(0);
    }

    if (selected == SHOW_PROCESSES) {
        EntitiesManager::showEntities(SHOW_PROCESSES);
    }

    if (selected == SHOW_HUMAN_ACTIVITIES) {
        EntitiesManager::showEntities(SHOW_HUMAN_ACTIVITIES);
    }

    if (selected == SHOW_GAMES) {
        EntitiesManager::showEntities(SHOW_GAMES);
    }

    if (selected == SHOW_ESPORTS) {
        EntitiesManager::showEntities(SHOW_ESPORTS);
    }

    if (selected == SHOW_COMPETITIVE_SPORTS) {
        EntitiesManager::showEntities(SHOW_COMPETITIVE_SPORTS);
    }
}
