// Shape.h
#ifndef OOPAD_2026_SHAPE_H
#define OOPAD_2026_SHAPE_H

#include <string>

class Shape {
protected:
    int id;
    std::string color;
    std::string type;

    const double PI = 3.14159;
public:
    Shape() : id(-1), color("чёрный"), type("Фигура") {}
    Shape(const std::string& color, const std::string& type) : id(-1), color(color), type(type) {}
    Shape (const Shape& sh) : id(sh.id), color(sh.color), type(sh.type) {}

    virtual ~Shape() = default;
    std::string getColor() const;
    std::string getType() const;

    void setId(int);
    void setColor(const std::string &);
    void setType(const std::string &);

    int getId() const;
    virtual double getSquare() const = 0;
    virtual double getVolume() const { return 0.0; }

    virtual void print() const;
    virtual void printInFile() const;
};


#endif //OOPAD_2026_SHAPE_H