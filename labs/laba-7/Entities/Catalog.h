// Catalog.h
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

template<class T>
Catalog<T>::Catalog (const Catalog &catalog) : name(catalog.name) {
    for (T* item : catalog.items) {
        items.push_back(new T(*item));
    }
}

template<class T>
Catalog<T>::~Catalog() {
    for (T* item : items) {
        delete item;
    }
    items.clear();
}

template<class T>
void Catalog<T>::add(T* item) {
    items.push_back(item);
}

template<class T>
bool Catalog<T>::remove(int id) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            items.erase(it);
            return true;
        }
    }
    return false;
}

template<class T>
T* Catalog<T>::findById(int id) const {
    for (T* item : items) {
        if (item->getId() == id) return item;
    }
    return nullptr;
}

template<class T>
const std::vector<T*>& Catalog<T>::getAll() const {
    return items;
}

template<class T>
std::string Catalog<T>::getName() const {
    return name;
}

template<class T>
void Catalog<T>::setName(const std::string& n) {
    name = n;
}

template<class T>
int Catalog<T>::getCount() const {
    return static_cast<int>(items.size());
}

#endif //OOPAD_2026_CATALOG_H