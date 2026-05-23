#include "Controller/SixthLabMenu.h"

#include <locale>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    SixthLabMenu menu;
    menu.init({"Показать процессы", "Показать объекты клсса \"Человеческая деятельность\"", "Показать игры", "Показать киберспортивные игры", "Показать соревновательный спорт"}, "Меню шестой лабораторной работы");

    return 0;
}