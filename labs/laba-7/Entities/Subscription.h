#ifndef OOPAD_2026_SUBSCIRPTION_H
#define OOPAD_2026_SUBSCIRPTION_H

#include "Reader.h"
#include "Book.h"

#include <vector>

class Subscirption {
    int id;
    Reader* reader;
    std::vector<Book*> books;
    std::string issueDate;
    std::string returnDate;
    int workerCount;
public:
    Subscription() : id(0), reader(nullptr), issueDate(""), returnDate(""), workerCount(0) {}

    Subscription(int id, Reader* reader, const std::string& issueDate, const std::string& returnDate)
        : id(id), reader(reader), issueDate(issueDate), returnDate(returnDate), workerCount(0) {}

    Subscription(const Subscription& other)
        : id(other.id), reader(other.reader), books(other.books),
          issueDate(other.issueDate), returnDate(other.returnDate),
          workerCount(0) {}

    ~Subscription();

    int getId() const;
    Reader* getReader() const;
    const std::vector<Book*>& getBooks();
    std::string getIssueDate() const;
    std::string getReturnDate() const;
    int getWorkerCount() const;

    void setId(int);
    void setReader(Reader *);
    void setIssueDate(const std::string &);
    void setReturnDate(const std::string &);

    void lock();
    void unlock();
    bool isEditable() const;
    void addBook(Book *);
    void removeBook(int);
    void print() const;

};


#endif //OOPAD_2026_SUBSCIRPTION_H