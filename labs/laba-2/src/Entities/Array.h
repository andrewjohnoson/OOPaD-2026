//Array.h
#ifndef OOPAD_2026_ARRAY_H
#define OOPAD_2026_ARRAY_H

class Array {
    int sizeRows, sizeCols;
    int **intArray = nullptr;
    float **floatArray = nullptr;
    bool isInitialized = false;
    int arrayIs = -1;

    void inputSize();
    void initArray(int);
    void fillRandomNumbers() const;
public:
    static const int INT_ARRAY = 1, FLOAT_ARRAY = 2;

    Array(int = 0, int = 0);
    Array(const Array &);
    ~Array();
    void deleteArray();
    void sortPos() const;
    void setSize(int, int);
    void inputArray(int);
    void outputArray() const;
};

#endif //OOPAD_2026_ARRAY_H