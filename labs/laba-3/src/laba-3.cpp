#include <iostream>

#include "Controller/ThirdLabMenu.h"
#include "Entity/Distance.h"

#include <vector>
#include <string>

int main()
{
    const std::vector<std::string> menuSettings ({
        "Ввести 1-ю дистанцию",
        "Ввести 2-ю дистанцию",
        "Сложить дистанции",
        "Показать разницу",
        "Проверить на равенство",
        "Вывести дистанции"
    });
    const std::string menuTitle = "Меню 3-й лабораторной работы";

    ThirdLabMenu menu;
    menu.init(menuSettings, menuTitle);

    return 0;
}

