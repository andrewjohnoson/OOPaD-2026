// LibraryManager.h
#ifndef OOPAD_2026_LIBRARYMANAGER_H
#define OOPAD_2026_LIBRARYMANAGER_H

#include "../Entities/Library.h"

class LibraryManager {
public:
    static void addBook(Library &);
    static void addReader(Library &);
    static void addEmployee(Library &);
    static void createSubscription(Library &);
    static void assignEmployee(Library &);
    static void releaseEmployee(Library &);
    static void addBookToSubscription(Library &);
    static void printLibInfo(Library &);
    static void changeLibInfo(Library &);
    static void load(Library &);
    static void save(Library &);
};


#endif //OOPAD_2026_LIBRARYMANAGER_H