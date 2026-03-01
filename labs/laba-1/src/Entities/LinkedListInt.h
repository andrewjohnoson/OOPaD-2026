// LinkedListInt.h
#ifndef OOPAD_2026_LINKEDLISTINT_H
#define OOPAD_2026_LINKEDLISTINT_H

class LinkedListInt {
    int* listInt;
    int size;
    int id;
public:
    LinkedListInt();
    LinkedListInt(int, const int [], int);
    LinkedListInt(const LinkedListInt&);
    ~LinkedListInt();
    void pushFront(int);
    void pushBack(int);
    int popFront();
    int popBack();
    void view();
    int find(int);
    void clear();
    static void sort(const LinkedListInt *, int);
    void removeElement(int);

    int* getList();
    int getSize();
    void setList(const LinkedListInt &);
    void setId(int);
    int getId();
};


#endif //OOPAD_2026_LINKEDLISTINT_H