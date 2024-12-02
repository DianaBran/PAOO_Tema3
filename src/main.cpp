#include "Matrix.h"

int main() {
    // Test constructor
    Matrix m1(2, 2);
    m1.setValue(0, 0, 1);
    m1.setValue(0, 1, 2);
    m1.setValue(1, 0, 3);
    m1.setValue(1, 1, 4);
    
    std::cout << "Original matrix m1:\n";
    m1.print();
    
    // Test copy constructor (Item 12)
    Matrix m2 = m1;
    std::cout << "\nCopy constructed matrix m2:\n";
    m2.print();
    
    // Test assignment operator (Item 10 & 11)
    Matrix m3;
    m3 = m1;  // Should return reference to m3
    std::cout << "\nAssigned matrix m3:\n";
    m3.print();
    
    // Test self-assignment (Item 11)
    m1 = m1;
    std::cout << "\nAfter self-assignment, m1:\n";
    m1.print();
    
    // Test move semantics
    Matrix m4 = std::move(m1);
    std::cout << "\nMove constructed matrix m4:\n";
    m4.print();
    
    return 0;
}