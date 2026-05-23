// Subscription.h
#ifndef OOPAD_2026_SUBSCIRPTION_H
#define OOPAD_2026_SUBSCIRPTION_H

#include "Reader.h"
#include "Book.h"

#include <vector>

class Subscription {
    int id;
    Reader* reader;
    std::vector<Book*> books;
    int workerCount;
public:
    Subscription() : id(0), reader(nullptr), workerCount(0) {}

    Subscription(const int id, Reader* reader)
        : id(id), reader(reader), workerCount(0) {}

    Subscription(const Subscription& s)
        : id(s.id), reader(s.reader), books(s.books),
          workerCount(0) {}

    ~Subscription();

    int getId() const;
    Reader* getReader() const;
    const std::vector<Book*>& getBooks() const;
    int getWorkerCount() const;

    void setId(int);
    void setReader(Reader *);
    void setWorkerCount(int);

    void lock();
    void unlock();
    bool isEditable() const;
    void addBook(Book *);
    void removeBook(int);
    void print() const;

};


#endif //OOPAD_2026_SUBSCIRPTION_H