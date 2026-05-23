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
    std::vector<std::shared_ptr<Employee>> employees;

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
    void addBook(const std::shared_ptr<Book> &);
    std::shared_ptr<Book> findBook(int);
    const Catalog<Book>& getBooks() const;

    // Читатели
    void addReader(const std::shared_ptr<Reader> &);
    std::shared_ptr<Reader> findReader(int) const;
    const Catalog<Reader>& getReaders() const;

    // Сотрудники
    void addEmployee(const std::shared_ptr<Employee> &);
    std::shared_ptr<Employee> findEmployee(int) const;
    const std::vector<std::shared_ptr<Employee>>& getEmployees() const;

    // Абонементы
    void addSubscription(const std::shared_ptr<Subscription> &);
    std::shared_ptr<Subscription> findSubscription(int) const;
    std::shared_ptr<Subscription> findSubscriptionByUser(int) const;
    const Catalog<Subscription>& getSubscriptions() const;

    void printInfo() const;
};


#endif //OOPAD_2026_LIBRARY_H