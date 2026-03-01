// LinkedListInt.cpp
#include "LinkedListInt.h"

#include <iostream>

LinkedListInt::LinkedListInt() {
    this->listInt = nullptr;
    this->size = 0;
    this->id = 0;
}

LinkedListInt::LinkedListInt(const int size, const int array[], const int id) {
    this->size = size;
    this->listInt = new int[size];
    for (int i = 0; i < size; i++) {
        this->listInt[i] = array[i];
    }
    this->id = id;
}

LinkedListInt::LinkedListInt(const LinkedListInt& list) {
    this->size = list.size;
    this->listInt = new int[this->size];
    for (int i = 0; i < this->size; i++) {
        this->listInt[i] = list.listInt[i];
    }
    this->id = list.id;
}

LinkedListInt::~LinkedListInt() {
    delete[] this->listInt;
}

int LinkedListInt::find(const int value) {
    for (int i = 0; i < this->size; i++) {
        if (this->listInt[i] == value) {
            return i;
        }
    }
    return -1;
}

void LinkedListInt::view() {
    if (this->size == 0) {
        std::cout << "ID списка: " << this->id << std::endl;
        std::cout << "Элементы списка: " << std::endl << std::endl;
        return;
    }

    std::cout << "ID списка: " << this->id << std::endl;
    std::cout << "Элементы списка: ";
    for (int i = 0; i < this->size; i++) {
        std::cout << this->listInt[i] << " ";
    }

    std::cout << std::endl;
}

void LinkedListInt::pushFront(const int value) {
    this->size++;

    int* temp = new int[this->size];

    temp[0] = value;
    for (int i = 1; i < this->size; i++) {
        temp[i] = this->listInt[i - 1];
    }

    delete[] this->listInt;
    this->listInt = temp;
    temp = nullptr;
}

void LinkedListInt::pushBack(const int value) {
    this->size++;

    int* temp = new int[this->size];

    for (int i = 0; i < this->size - 1; i++) {
        temp[i] = this->listInt[i];
    }

    temp[this->size - 1] = value;

    delete[] this->listInt;
    this->listInt = temp;
    temp = nullptr;
}

int LinkedListInt::popFront() {
    if (this->size == 0) {
        std::cout << "В списке нету элементов." << std::endl;
        return -1;
    }

    int value = this->listInt[0];

    int *temp = new int[--this->size];
    for (int i = 0; i < this->size; i++) {
        temp[i] = this->listInt[i + 1];
    }

    delete[] this->listInt;
    this->listInt = temp;
    temp = nullptr;
    return value;
}

int LinkedListInt::popBack() {
    if (this->size == 0) {
        std::cout << "В списке нету элементов." << std::endl;
        return -1;
    }

    int value = this->listInt[this->size - 1];

    int *temp = new int[--this->size];
    for (int i = 0; i < this->size; i++) {
        temp[i] = this->listInt[i];
    }

    delete[] this->listInt;
    this->listInt = temp;
    temp = nullptr;
    return value;
}


void LinkedListInt::clear() {
    if (this->size == 0) {
        return;
    }

    delete[] this->listInt;
    this->size = 0;
    this->listInt = nullptr;
}

void LinkedListInt::sort(const LinkedListInt* list, const int param = 0) {
    if (param < 0 || param > 1) {
        std::cout << "Параметр задан неправильно." << std::endl;
        return;
    }

    if (list->size == 0) {
        std::cout << "Невозможно отсортировать: список пуст." << std::endl;
        return;
    }

    for (int i = 0; i < list->size - 1; i++) {
        for (int j = i + 1; j < list->size; j++) {
            if (param == 0) {
                if (list->listInt[i] > list->listInt[j]) {
                    std::swap(list->listInt[i], list->listInt[j]);
                }
            } else if (param == 1) {
                if (list->listInt[i] < list->listInt[j]) {
                    std::swap(list->listInt[i], list->listInt[j]);
                }
            }
        }
    }
}

void LinkedListInt::removeElement(const int value) {
    if (this->size == 0) {
        std::cout << "Список не задан." << std::endl;
        return;
    }

    int index = 0;
    do {
        index = this->find(value);
        if (index == -1) {
            return;
        }

        int* temp = new int[this->size - 1];
        for (int i = 0; i < index; i++) {
            temp[i] = this->listInt[i];
        }
        for (int i = index + 1; i < this->size; i++) {
            temp[i - 1] = this->listInt[i];
        }

        this->size--;
        delete[] this->listInt;
        this->listInt = temp;
        temp = nullptr;
    } while (true);
}

void LinkedListInt::setList(const LinkedListInt &list) {
    this->size = list.size;

    delete[] this->listInt;

    this->listInt = new int[this->size];
    for (int i = 0; i < this->size; i++) {
        this->listInt[i] = list.listInt[i];
    }
}

int* LinkedListInt::getList() {
    if (this->listInt == nullptr) {
        return nullptr;
    }
    return this->listInt;
}

int LinkedListInt::getSize() {
    if (this->size == 0) {
        return -1;
    }
    return this->size;
}

void LinkedListInt::setId(const int id) {
    if (id < 1) {
        std::cout << "Не назачено." << std::endl;
        return;
    }

    this->id = id;
}

int LinkedListInt::getId() {
    return this->id;
}

