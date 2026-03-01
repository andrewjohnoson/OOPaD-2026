// LinkedListString.h
#ifndef OOPAD_2026_LINKEDLISTSTRING_H
#define OOPAD_2026_LINKEDLISTSTRING_H

#include <iostream>
#include <string>

class LinkedListString {
    std::string *listString;
    int size;
    int id;
public:
    LinkedListString();
    LinkedListString(int, const std::string *, int);
    LinkedListString(const LinkedListString &);
    ~LinkedListString();

    void pushFront(const std::string &);
    void pushBack(const std::string &);
    std::string popFront();
    std::string popBack();
    void view();
    int find(const std::string &);
    void clear();
    static void sort(const LinkedListString *, int);
    void removeElement(const std::string&);

    void setList (const LinkedListString &);
    void setId(int);
    std::string* getList();
    int getSize();
    int getId();
};

#endif //OOPAD_2026_LINKEDLISTSTRING_H