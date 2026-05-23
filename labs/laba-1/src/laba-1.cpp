// laba-1.cpp
#include "Controller/FirstLabMenu.h"

#include <vector>
#include <string>
#include <locale>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    const std::vector<std::string> lines ({"Работа с классом LinkedListInt",
        "Работа с классом LinkedListString.",
        });

    const std::string headTitle = "Меню 1-й лабораторной работы";

    FirstLabMenu firstLabMenu;
    firstLabMenu.init(lines, headTitle);

    return 0;
}