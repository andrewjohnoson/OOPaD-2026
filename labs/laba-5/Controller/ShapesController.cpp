// ShapesController.cpp
#include "ShapesController.h"

#include <iostream>
#include <map>
#include <fstream>

#include "../../../libs/CheckInput.h"
#include "../../../libs/TerminalController.h"

#include "../Entities/Shape.h"
#include "../Entities/Circle.h"
#include "../Entities/Square.h"
#include "../Entities/Triangle.h"
#include "../Entities/Pyramid.h"

std::vector <Shape*> ShapesController::shapesList;
int ShapesController::idCounter = 1;

void ShapesController::addShapes() {
    std::cout << "Сколько записей хотите добавить (введите -1 для выхода): ";
    const int amount = CheckInput::inputIndex();

    if (amount == -1) {
        return;
    }

    for (int i = 0; i < amount; i++) {
        int choice;

        while (true) {
            std::cout << "Какую фигуру хотите ввести (1 - круг, 2 - квадрат, 3 - треугольник, 4 - пирамида): ";
            choice = CheckInput::inputInt();

            if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
                break;
            }

            std::cout << "Введено некорректное значение. Повторите ввод." << std::endl;
        }

        Shape* shape = nullptr;

        if (choice == 1) {
            std::cout << "Введите радиус: ";
            const double r = CheckInput::inputDouble();

            Circle* circle = new Circle(r);
            circle->setId(idCounter);
            shape = circle;
        }

        if (choice == 2) {
            std::cout << "Введите сторону основания: ";
            const double side = CheckInput::inputDouble();

            Square* square = new Square();
            square->setSide(side);
            square->setId(idCounter);
            shape = square;
        }

        if (choice == 3) {
            std::cout << "Введите сторону a: ";
            double a = CheckInput::inputDouble();

            std::cout << "Введите сторону b: ";
            double b = CheckInput::inputDouble();

            std::cout << "Введите сторону c: ";
            double c = CheckInput::inputDouble();

            Triangle* triangle = new Triangle(a, b, c);
            triangle->setId(idCounter);
            shape = triangle;
        }

        if (choice == 4) {
            std::cout << "Введите сторону основания: ";
            double side = CheckInput::inputDouble();

            std::cout << "Введите высоту: ";
            double height = CheckInput::inputDouble();

            Pyramid* pyramid = new Pyramid(side, height);
            pyramid->setId(idCounter);
            shape = pyramid;
        }

        shapesList.push_back(shape);
        idCounter++;
        std::cout << std::endl;
    }

    std::cout << "Введено" << std::endl;
    TerminalController::waitForClick();
}

void ShapesController::showAllShapes() {
    if (shapesList.empty()) {
        std::cout << "Список фигур пуст." << std::endl;
    } else {
        for (const Shape* shape : shapesList) {
            shape->print();
            std::cout << std::endl;
        }
    }

    TerminalController::waitForClick();
}

void ShapesController::showEqualShapes() {
    std::fstream fout("/Users/andrey/Desktop/UNIVERSITY/OOPaD/OOPaD-2026/labs/laba-5/files/shapes.txt", std::ios::app);
    std::cout << std::endl << "Фигуры с одинаковыми площадями:" << std::endl;
    fout << std::endl << "Фигуры с одинаковыми площадями:" << std::endl;

    std::map<double, std::vector<Shape*>> bySquare;
    for (Shape* shape : shapesList) {
        bySquare[shape->getSquare()].push_back(shape);
    }

    bool foundSquare = false;
    for (auto& pair : bySquare) {
        if (pair.second.size() > 1) {
            foundSquare = true;
            for (Shape* shape : pair.second) {
                shape->print();
                shape->printInFile();
                std::cout << std::endl;
            }
        }
    }
    if (!foundSquare) {
        std::cout << std::endl << "Фигур с одинаковыми площадями не найдено." << std::endl;
        fout << std::endl << "Фигур с одинаковыми площадями не найдено." << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl << "Фигуры с одинаковым объёмом:" << std::endl;
    fout << std::endl << "Фигуры с одинаковым объёмом:" << std::endl;

    std::map<double, std::vector<Shape*>> byVolume;
    for (Shape* shape : shapesList) {
        double vol = shape->getVolume();
        if (vol > 0.0) {
            byVolume[vol].push_back(shape);
        }
    }

    bool foundVolume = false;
    for (auto& pair : byVolume) {
        if (pair.second.size() > 1) {
            foundVolume = true;
            for (Shape* shape : pair.second) {
                shape->print();
                shape->printInFile();
                std::cout << std::endl;
            }
        }
    }


    if (!foundVolume) {
        std::cout << std::endl << "Фигур с одинаковым объёмом не найдено." << std::endl;
        fout << std::endl << "Фигур с одинаковым объёмом не найдено." << std::endl;
    }

    fout << std::endl << "---------------------------------------------" << std::endl;

    TerminalController::waitForClick();
}
