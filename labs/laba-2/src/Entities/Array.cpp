//Array.cpp
#include "Array.h"

#include <iostream>

#include "../../../../libs/CheckInput.h"
#include "../../../../libs/TerminalController.h"
#include "../Controller/Manipulator.h"

Array::Array(const int sizeRows, const int sizeColumns) {
    this->sizeRows = sizeRows;
    this->sizeCols = sizeColumns;
}

Array::Array(const Array & obj) {
    sizeRows = obj.sizeRows;
    sizeCols = obj.sizeCols;
    isInitialized = obj.isInitialized;
    arrayIs = obj.arrayIs;

    if (arrayIs == INT_ARRAY) {
        intArray = new int* [sizeRows];
        for (int i = 0; i < sizeRows; i++) {
            intArray[i] = new int[sizeCols];
        }

        for (int i = 0; i < sizeRows; i++) {
            for (int j = 0; j < sizeCols; j++) {
                intArray[i][j] = obj.intArray[i][j];
            }
        }
    }

    if (arrayIs == FLOAT_ARRAY) {
        floatArray = new float* [sizeRows];
        for (int i = 0; i < sizeRows; i++) {
            floatArray[i] = new float[sizeCols];
        }

        for (int i = 0; i < sizeRows; i++) {
            for (int j = 0; j < sizeCols; j++) {
                floatArray[i][j] = obj.floatArray[i][j];
            }
        }
    }
}

Array::~Array() {
    if (arrayIs == INT_ARRAY) {
        for (int i = 0; i < sizeRows; i++) {
            delete[] intArray[i];
        }
        delete[] intArray;
    }

    if (arrayIs == FLOAT_ARRAY) {
        for (int i = 0; i < sizeRows; i++) {
            delete[] floatArray[i];
        }
        delete[] floatArray;
    }
}

void Array::setSize(const int sizeRows, const int sizeCols) {
    this->sizeRows = sizeRows;
    this->sizeCols = sizeCols;
}

void Array::inputArray(const int arrayCode) {
    inputSize();
    initArray(arrayCode);

    std::cout << "Массив инициализирован." << std::endl;
    TerminalController::waitForClick();
}

void Array::inputSize() {
    std::cout << "Введите количество строк: ";
    const int n = CheckInput::inputNatural();
    std::cout << "Введите количество столбцов: ";
    const int m = CheckInput::inputNatural();

    this->setSize(n, m);
}

void Array::initArray(const int arrayCode) {
    if (isInitialized) {
        std::cout << "Массив уже создан.";
        TerminalController::waitForClick();
        return;
    }

    if (arrayCode == INT_ARRAY) {
        intArray = new int* [sizeRows];
        for (int i = 0; i < sizeRows; i++) {
            intArray[i] = new int[sizeCols];
        }

        isInitialized = true;
        arrayIs = arrayCode;
        fillRandomNumbers();
    }

    if (arrayCode == FLOAT_ARRAY) {
        floatArray = new float* [sizeRows];
        for (int i = 0; i < sizeRows; i++) {
            floatArray[i] = new float[sizeCols];
        }
        isInitialized = true;
        arrayIs = arrayCode;
        fillRandomNumbers();
    }
}

void Array::fillRandomNumbers() const {
    srand(time(0));
    if (arrayIs == INT_ARRAY) {
        for (int i = 0; i < sizeRows; i++) {
            for (int j = 0; j < sizeCols; j++) {
                intArray[i][j] = rand() % 21 - 10;
            }
        }
    }

    if (arrayIs == FLOAT_ARRAY) {
        for (int i = 0; i < sizeRows; i++) {
            for (int j = 0; j < sizeCols; j++) {
                floatArray[i][j] = (float) rand() / (RAND_MAX + 1.0) * 40 - 20;
            }
        }
    }
}

void Array::deleteArray() {
    if (!isInitialized) {
        std::cout << "Массив не создан." << std::endl;
        TerminalController::waitForClick();
        return;
    }

    if (arrayIs == INT_ARRAY) {
        for (int i = 0; i < sizeRows; i++) {
            delete[] intArray[i];
        }
        delete[] intArray;
    }

    if (arrayIs == FLOAT_ARRAY) {
        for (int i = 0; i < sizeRows; i++) {
            delete[] floatArray[i];
        }
        delete[] floatArray;
    }

    isInitialized = false;
    arrayIs = -1;
    sizeRows = 0, sizeCols = 0;

    std::cout << "Массив удалён." << std::endl;
    TerminalController::waitForClick();
}

void Array::sortPos() const {
    if (!isInitialized) {
        std::cout << "Массив не создан." << std::endl;
        TerminalController::waitForClick();
        return;
    }

    if (arrayIs == INT_ARRAY) {
        for (int i = 0; i < sizeRows; i++) {
            for (int j = 0; j < sizeCols; j++) {
                for (int k = j + 1; k < sizeCols; k++) {
                    if (intArray[i][j] > intArray[i][k] &&
                        intArray[i][j] > 0 && intArray[i][k] > 0) {
                            std::swap(intArray[i][j], intArray[i][k]);
                    }
                }
            }
        }
    }

    if (arrayIs == FLOAT_ARRAY) {
        for (int i = 0; i < sizeRows; i++) {
            for (int j = 0; j < sizeCols; j++) {
                for (int k = j + 1; k < sizeCols; k++) {
                    if (floatArray[i][j] > floatArray[i][k] &&
                        floatArray[i][j] > 0 && floatArray[i][k] > 0) {
                        std::swap(floatArray[i][j], floatArray[i][k]);
                        }
                }
            }
        }
    }

    std::cout << "Отсортирован" << std::endl;
    TerminalController::waitForClick();
}

void Array::outputArray() const {
    if (!isInitialized) {
        std::cout << "Массив не создан" << std::endl;
        TerminalController::waitForClick();
        return;
    }

    if (arrayIs == INT_ARRAY) {
        std::cout << Manipulator::setForIntIterator << "int " << "|| ";
        for (int i = 0; i < sizeCols; i++) {
            std::cout << Manipulator::setForNumbers << i + 1 << "| ";
        }
        std::cout << std::endl;
        for (int i = 0; i < 6 + 10 * sizeCols; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        for (int i = 0; i < sizeRows; i++) {
            std::cout << Manipulator::setForIntIterator << i + 1 << "|| ";
            for (int j = 0; j < sizeCols; j++) {
                std::cout << Manipulator::setForNumbers << intArray[i][j] << "| ";
            }
            std::cout << std::endl;
        }

        TerminalController::waitForClick();
    }

    if (arrayIs == FLOAT_ARRAY) {
        std::cout << Manipulator::setForFloatIterator << "float " << "|| ";
        for (int i = 0; i < sizeCols; i++) {
            std::cout << Manipulator::setForNumbers << i + 1 << "| ";
        }
        std::cout << std::endl;
        for (int i = 0; i < 8 + 10 * sizeCols; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        for (int i = 0; i < sizeRows; i++) {
            std::cout << Manipulator::setForFloatIterator << i + 1 << "|| ";
            for (int j = 0; j < sizeCols; j++) {
                std::cout << Manipulator::setForNumbers << floatArray[i][j] << "| ";
            }
            std::cout << std::endl;
        }

        TerminalController::waitForClick();
    }
}