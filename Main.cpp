//souldaher210@gmail.com

#include "SquareMat.hpp"
#include <iostream>

using namespace matlib;

int main() {
    SquareMat A(2);
    SquareMat B(2);

    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;

    std::cout << "Matrix A:\n" << A << std::endl;
    std::cout << "Matrix B:\n" << B << std::endl;

    std::cout << "A + B:\n" << (A + B) << std::endl;
    std::cout << "A * B:\n" << (A * B) << std::endl;
    std::cout << "Transpose of A (~A):\n" << ~A << std::endl;
    std::cout << "Determinant of A (!A): " << !A << std::endl;

    return 0;
}
