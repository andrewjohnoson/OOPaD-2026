// LinkedListString.cpp
#include "LinkedListString.h"

#include <iostream>
#include <string>

LinkedListString::LinkedListString() {
    this->listString = nullptr;
    this->size = 0;
    this->id = 0;
}

LinkedListString::LinkedListString(const int size, const std::string array[], const int id) {
    this->size = size;
    this->id = id;
    this->listString = new std::string[size];
    for (int i = 0; i < this->size; i++) {
        this->listString[i] = array[i];
    }
}

LinkedListString::LinkedListString(const LinkedListString& list) {
    this->size = list.size;
    this->listString = new std::string[this->size];
    for (int i = 0; i < this->size; i++) {
        this->listString[i] = list.listString[i];
    }
    this->id = list.id;
}

LinkedListString::~LinkedListString() {
    delete[] this->listString;
}

int LinkedListString::find(const std::string& value) {
    for (int i = 0; i < this->size; i++) {
        if (this->listString[i] == value) {
            return i;
        }
    }
    return -1;
}

void LinkedListString::view() {
    if (this->size == 0) {
        std::cout << "ID списка: " << this->id << std::endl;
        std::cout << "Элементы списка: " << std::endl << std::endl;
        return;
    }

    std::cout << "ID списка: " << this->id << std::endl;
    std::cout << "Элементы списка: ";
    for (int i = 0; i < this->size; i++) {
        std::cout << "\"" << this->listString[i] << "\" ";
    }

    std::cout << std::endl;
}

void LinkedListString::pushFront(const std::string& value) {
    this->size++;

    std::string *temp = new std::string[this->size];

    temp[0] = value;
    for (int i = 1; i < this->size; i++) {
        temp[i] = this->listString[i - 1];
    }

    delete[] this->listString;
    this->listString = temp;
    temp = nullptr;
}

void LinkedListString::pushBack(const std::string& value) {
    this->size++;

    std::string *temp = new std::string[this->size];

    for (int i = 0; i < this->size - 1; i++) {
        temp[i] = this->listString[i];
    }

    temp[this->size - 1] = value;

    delete[] this->listString;
    this->listString = temp;
    temp = nullptr;
}

std::string LinkedListString::popFront() {
    if (this->size == 0) {
        std::cout << "В списке нету элементов." << std::endl;
        return "";
    }

    std::string value = this->listString[0];

    std::string *temp = new std::string[--this->size];

    for (int i = 0; i < this->size; i++) {
        temp[i] = this->listString[i + 1];
    }

    delete[] this->listString;
    this->listString = temp;
    temp = nullptr;
    return value;
}

std::string LinkedListString::popBack() {
    if (this->size == 0) {
        std::cout << "В списке нету элементов." << std::endl;
        return "";
    }

    std::string value = this->listString[this->size - 1];

    std::string *temp = new std::string[--this->size];

    for (int i = 0; i < this->size; i++) {
        temp[i] = this->listString[i];
    }

    delete[] this->listString;
    this->listString = temp;
    temp = nullptr;
    return value;
}

void LinkedListString::clear() {
    this->size = 0;
    delete[] this->listString;
    std::cout << "Список очищен." << std::endl;
}

void LinkedListString::sort(const LinkedListString* list, const int param = 0) {
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
                if (list->listString[i] > list->listString[j]) {
                    std::swap(list->listString[i], list->listString[j]);
                }
            } else if (param == 1) {
                if (list->listString[i] < list->listString[j]) {
                    std::swap(list->listString[i], list->listString[j]);
                }
            }
        }
    }
}

void LinkedListString::removeElement(const std::string& value) {
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

        std::string* temp = new std::string[this->size - 1];
        for (int i = 0; i < index; i++) {
            temp[i] = this->listString[i];
        }
        for (int i = index + 1; i < this->size; i++) {
            temp[i - 1] = this->listString[i];
        }

        this->size--;
        delete[] this->listString;
        this->listString = temp;
        temp = nullptr;
    } while (true);
}

void LinkedListString::setList(const LinkedListString &list) {
    this->size = list.size;
    delete[] this->listString;
    this->listString = new std::string[this->size];
    for (int i = 0; i < this->size; i++) {
        this->listString[i] = list.listString[i];
    }
}

std::string* LinkedListString::getList() {
    if (this->listString == nullptr) {
        return nullptr;
    }
    return this->listString;
}

int LinkedListString::getSize() {
    if (this->size == 0) {
        return -1;
    }
    return this->size;
}

void LinkedListString::setId(const int id) {
    if (id < 1) {
        std::cout << "Не назначено." << std::endl;
        return;
    }

    this->id = id;
}

int LinkedListString::getId() {
    return this->id;
}