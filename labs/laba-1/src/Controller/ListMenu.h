// ListMenu.h
#ifndef OOPAD_2026_LISTMENU_H
#define OOPAD_2026_LISTMENU_H

#include "../../../../libs/Menu.h"

#include <vector>
#include <string>

class ListMenu : public Menu {
protected:
    void showMenu() override;
    void doMenuAction(int) override;
    int menuCounter = 0;

private:
    std::vector<std::string> menuPoints = {
        "Cоздать массив объектов класса",
        "Cчитать данные объектов с клавиатуры",
        "Вывести данные объектов на экран и в файл",
        "Добавить элемент в список",
        "Удалить элемент из списка",
        "Поиск элемента в списке",
        "Сортировка списка",
    };

    int param = -1;
    const int LINKED_LIST_INT = 1, LINKED_LIST_STRING = 2;
    const int CREATE_OBJECTS_ARRAY = 1, READ_OBJECTS_DATA = 2, OUTPUT_OBJECTS_DATA = 3,
            ADD_ELEMENT_TO_LIST = 4, REMOVE_ELEMENT_FROM_LIST = 5, FIND_ELEMENT_IN_LIST = 6, SORT_LIST = 7, EXIT = 8;

public:
    void init(int);
};



#endif //OOPAD_2026_LISTMENU_H