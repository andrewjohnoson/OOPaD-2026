// Reader.h
#ifndef OOPAD_2026_READER_H
#define OOPAD_2026_READER_H

#include <string>

class Reader {
    int id;
    std::string fullName;
public:
    Reader() : id(0), fullName("Unknown") {}

    Reader(int id, const std::string& fullName)
        : id(id), fullName(fullName) {}

    Reader(const Reader& other)
        : id(other.id), fullName(other.fullName) {}

    int getId() const;
    std::string getFullName() const;

    void setId(int);
    void setFullName(const std::string &);

    void print() const;
};


#endif //OOPAD_2026_READER_H