// #include "Entities/Array.h"
#include "Controller/SecondLabMenu.h"

#include <vector>
#include <string>

int main() {
    const std::vector<std::string> menuSettings({"Создать массив целых чисел", "Создать массив вещественных чисел",
                "Сортировать массив", "Вывести массив" ,"Удалить массив"});
    const std::string menuTitle = "Меню 2-й лабораторной работы";

    SecondLabMenu menu;
    menu.init(menuSettings, menuTitle);

    return 0;
}
