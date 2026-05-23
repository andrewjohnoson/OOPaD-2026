#ifndef OOPAD_2026_CATALOG_H
#define OOPAD_2026_CATALOG_H

#include <vector>
#include <string>

template <typename T>
class Catalog {
    std::vector <T*> items;
    std::string name;
public:
    Catalog() : name("Безымянный") {}
    Catalog(const std::string &name) : name(name) {}
    Catalog(const Catalog &);

    ~Catalog();

    void add(T*);

    bool remove(int);

    T* findById(int) const;

    const std::vector<T*>& getAll() const;
    std::string getName() const;
    void setName(const std::string&);
    int getCount() const;

};


#endif //OOPAD_2026_CATALOG_H