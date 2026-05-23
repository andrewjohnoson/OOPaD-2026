// Subscription.h
#ifndef OOPAD_2026_SUBSCIRPTION_H
#define OOPAD_2026_SUBSCIRPTION_H

#include "Reader.h"
#include "Book.h"
#include "Transaction.h"

#include <vector>

class Subscription {
    int id;
    std::shared_ptr<Reader> reader;
    std::vector<std::shared_ptr<Book>> books;
    int workerCount;

    Transaction<std::vector<std::shared_ptr<Book>>> transaction;
public:
    Subscription() : id(0), reader(nullptr), workerCount(0) {}

    Subscription(const int id, const std::shared_ptr<Reader> &reader)
        : id(id), reader(reader), workerCount(0) {}

    Subscription(const std::shared_ptr<Subscription> &s)
        : id(s->id), reader(s->reader), books(s->books),
          workerCount(0) {}

    ~Subscription();

    int getId() const;
    std::shared_ptr<Reader> getReader() const;
    const std::vector<std::shared_ptr<Book>>& getBooks() const;
    int getWorkerCount() const;

    void setId(int);
    void setReader(const std::shared_ptr<Reader> &);
    void setWorkerCount(int);

    void lock();
    void unlock();
    bool isEditable() const;
    void addBook(const std::shared_ptr<Book> &);
    void removeBook(int);
    void print() const;

    void beginTransaction();
    void commit();
    void rollback();
    bool hasActiveTransaction();
};


#endif //OOPAD_2026_SUBSCIRPTION_H