#include "Controller/FifthLabMenu.h"

#include <vector>
#include <string>
#include <locale>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::string menuTitle = "Меню пятой лабораторной работы";
    std::vector<std::string> menuSettings ({"Добавить новую фигуру", "Показать список всех фигур", "Вывести фигуры с равной площадью или объёмом",
    });

    FifthLabMenu menu;

    menu.init(menuSettings, menuTitle);
}