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

    SquareMat(int size);
    SquareMat(const SquareMat& other);
    ~SquareMat();

    
    SquareMat& operator=(const SquareMat& other);

    
    double* operator[](int index);
    const double* operator[](int index) const;

    
    double sum() const;

    
    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator*(double scalar) const;
    SquareMat operator/(double scalar) const;
    SquareMat operator%(int scalar) const;
    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator^(int power) const;

    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator*=(double scalar);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(int scalar);
    SquareMat& operator%=(const SquareMat& other);

    SquareMat operator-() const;
    SquareMat operator~() const;
    double operator!() const;

    SquareMat& operator++();
    SquareMat operator++(int);
    SquareMat& operator--();
    SquareMat operator--(int);

    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;

    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
};

} 

#endif 
