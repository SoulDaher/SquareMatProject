//souldaher210@gmail.com

#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>
#include <cmath>

namespace matlib {

class SquareMat {
private:
    int size;
    double** data;

    void allocate();
    void free();
    void copyData(const SquareMat& other);

public:
    // Constructors and Destructor
    SquareMat(int size);
    SquareMat(const SquareMat& other);
    ~SquareMat();

    // Assignment operator
    SquareMat& operator=(const SquareMat& other);

    // Index operator
    double* operator[](int index);
    const double* operator[](int index) const;

    // Helper methods
    double sum() const;

    // Arithmetic operators
    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator*(double scalar) const;
    SquareMat operator/(double scalar) const;
    SquareMat operator%(int scalar) const;
    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator^(int power) const;

    // Compound assignment operators
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator*=(double scalar);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(int scalar);
    SquareMat& operator%=(const SquareMat& other);

    // Unary operators
    SquareMat operator-() const;
    SquareMat operator~() const;
    double operator!() const;

    // Increment/Decrement operators
    SquareMat& operator++();
    SquareMat operator++(int);
    SquareMat& operator--();
    SquareMat operator--(int);

    // Comparison operators
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
};

} // namespace matlib

#endif // SQUAREMAT_HPP