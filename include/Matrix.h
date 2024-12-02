#pragma once
#include <iostream>

class Matrix {
private:
    size_t rows;
    size_t cols;
    int** data;

    void allocateMemory();
    void deallocateMemory();

public:
    // Constructor
    Matrix(size_t rows = 2, size_t cols = 2);
    
    // Destructor
    ~Matrix();
    
    // Copy constructor (Item 12)
    Matrix(const Matrix& other);
    
    // Move constructor (cerința 6)
    Matrix(Matrix&& other) noexcept;
    
    // Assignment operator (Item 10, 11)
    Matrix& operator=(const Matrix& other);
    
    // Move assignment operator
    Matrix& operator=(Matrix&& other) noexcept;
    
    // Helper pentru afișare
    void print() const;
    
    // Setters/Getters
    void setValue(size_t i, size_t j, int value);
    int getValue(size_t i, size_t j) const;
};