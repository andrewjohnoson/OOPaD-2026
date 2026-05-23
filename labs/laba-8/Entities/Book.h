// Book.h
#ifndef OOPAD_2026_BOOK_H
#define OOPAD_2026_BOOK_H

#include <string>

class Book {
    int id;
    std::string title;
    std::string author;
    int year;
    int totalCopies;
    int availableCopies;
public:
    Book() : id(0), title("Unknown"), author("Unknown"), year(0),
             totalCopies(1), availableCopies(1) {}

    Book(int id, const std::string& title, const std::string& author,
         const int year, const int copies)
        : id(id), title(title), author(author), year(year),
          totalCopies(copies), availableCopies(copies) {}

    Book(const Book& b)
        : id(b.id), title(b.title), author(b.author),
          year(b.year), totalCopies(b.totalCopies),
          availableCopies(b.availableCopies) {}

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    int getTotalCopies() const;
    int getAvailableCopies() const;

    void setId(int);
    void setTitle(const std::string &);
    void setAuthor(const std::string &);
    void setYear(int);
    void setTotalCopies(int);
    void setAvailableCopies(int);

    bool takeOne();
    void returnOne();
    void print() const;
};


#endif //OOPAD_2026_BOOK_H