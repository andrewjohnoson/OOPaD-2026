// Library.h
#ifndef OOPAD_2026_LIBRARY_H
#define OOPAD_2026_LIBRARY_H

#include "Organisation.h"
#include "Catalog.h"
#include "Book.h"
#include "Reader.h"
#include "Subscription.h"
#include "Employee.h"

class Library : public Organisation {
    Catalog<Book> books;
    Catalog<Reader> readers;
    Catalog<Subscription> subscriptions;
    std::vector<Employee*> employees;

public:
    Library() : Organisation(),
          books("Каталог книг"), readers("Каталог читателей"),
          subscriptions("Каталог абонементов") {}

    Library(const std::string& orgName,
            const std::string& address)
        :
          Organisation(orgName, address),
          books("Каталог книг"), readers("Каталог читателей"),
          subscriptions("Каталог абонементов") {}

    Library(const Library& l)
        : Organisation(l),
          books(l.books), readers(l.readers),
          subscriptions(l.subscriptions) {}

    ~Library() override;

    // Книги
    void addBook(Book *);
    Book* findBook(int);
    const Catalog<Book>& getBooks() const;

    // Читатели
    void addReader(Reader *);
    Reader* findReader(int) const;
    const Catalog<Reader>& getReaders() const;

    // Сотрудники
    void addEmployee(Employee *);
    Employee* findEmployee(int) const;
    const std::vector<Employee*>& getEmployees() const;

    // Абонементы
    void addSubscription(Subscription *);
    Subscription* findSubscription(int) const;
    Subscription* findSubscriptionByUser(int) const;
    const Catalog<Subscription>& getSubscriptions() const;

    void printInfo() const;
};


#endif //OOPAD_2026_LIBRARY_H