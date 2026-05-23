#include <vector>
#include <string>
#include <locale>

#include "Controller/FourthLabMenu.h"

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    FourthLabMenu menu;
    std::string menuTitle = "Меню четвёртой лабораторной работы";
    std::vector<std::string> menuSettings ({"Добавить маршрут в список", "Изменить маршрут", "Вывести список", "Удалить маршрут",
    });

    menu.init(menuSettings, menuTitle);
    return 0;
}