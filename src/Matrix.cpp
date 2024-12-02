#include "Matrix.h"

void Matrix::allocateMemory() {
    data = new int*[rows];
    for(size_t i = 0; i < rows; ++i) {
        data[i] = new int[cols]();  // Inițializare cu 0
    }
}

void Matrix::deallocateMemory() {
    if(data) {
        for(size_t i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

// Constructor (cerința 3)
Matrix::Matrix(size_t r, size_t c) : rows(r), cols(c), data(nullptr) {
    allocateMemory();
}

// Destructor (cerința 4)
Matrix::~Matrix() {
    deallocateMemory();
}

// Copy constructor (cerința 5 și Item 12)
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(nullptr) {
    allocateMemory();
    for(size_t i = 0; i < rows; ++i) {
        for(size_t j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Move constructor (cerința 6)
Matrix::Matrix(Matrix&& other) noexcept 
    : rows(other.rows), cols(other.cols), data(other.data) {
    other.data = nullptr;
    other.rows = 0;
    other.cols = 0;
}

// Assignment operator (Item 10 & 11)
Matrix& Matrix::operator=(const Matrix& other) {
    if(this != &other) { // Handle self-assignment (Item 11)
        // Copy-and-swap idiom
        Matrix temp(other);  // Copy constructor creates temporary
        std::swap(rows, temp.rows);
        std::swap(cols, temp.cols);
        std::swap(data, temp.data);
    }
    return *this;  // Return reference to *this (Item 10)
}

// Move assignment operator
Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if(this != &other) {
        deallocateMemory();
        
        rows = other.rows;
        cols = other.cols;
        data = other.data;
        
        other.data = nullptr;
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}

void Matrix::print() const {
    for(size_t i = 0; i < rows; ++i) {
        for(size_t j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Matrix::setValue(size_t i, size_t j, int value) {
    if(i < rows && j < cols) {
        data[i][j] = value;
    }
}

int Matrix::getValue(size_t i, size_t j) const {
    if(i < rows && j < cols) {
        return data[i][j];
    }
    return 0;
}