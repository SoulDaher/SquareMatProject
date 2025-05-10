//souldaher210@gmail.com

#include "SquareMat.hpp"
#include <iostream>
#include <cmath>

namespace matlib {

SquareMat::SquareMat(int size) : size(size) {
    if (size <= 0) throw "Invalid matrix size";
    allocate();
}

SquareMat::SquareMat(const SquareMat& other) : size(other.size) {
    allocate();
    copyData(other);
}

SquareMat::~SquareMat() {
    free();
}

SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this != &other) {
        if (size != other.size) {
            free();
            size = other.size;
            allocate();
        }
        copyData(other);
    }
    return *this;
}

void SquareMat::allocate() {
    data = new double*[size];
    for (int i = 0; i < size; ++i)
        data[i] = new double[size]();
}

void SquareMat::free() {
    for (int i = 0; i < size; ++i)
        delete[] data[i];
    delete[] data;
}

void SquareMat::copyData(const SquareMat& other) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] = other.data[i][j];
}


double* SquareMat::operator[](int index) {
    return data[index];
}

const double* SquareMat::operator[](int index) const {
    return data[index];
}

double SquareMat::sum() const {
    double total = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            total += data[i][j];
    return total;
}


SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) throw "Matrix sizes do not match for addition.";
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] + other[i][j];
    return result;
}

SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size) throw "Matrix sizes do not match for subtraction.";
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] - other[i][j];
    return result;
}

SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) throw "Matrix sizes do not match for multiplication.";
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            for (int k = 0; k < size; ++k)
                result[i][j] += data[i][k] * other[k][j];
    return result;
}

SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] * scalar;
    return result;
}

SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar;
}

SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0) throw "Division by zero.";
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] / scalar;
    return result;
}

SquareMat SquareMat::operator%(int scalar) const {
    if (scalar == 0) throw "Modulo by zero.";
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = static_cast<int>(data[i][j]) % scalar;
    return result;
}

SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size) throw "Matrix sizes do not match for element-wise modulo.";
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = static_cast<int>(data[i][j]) % static_cast<int>(other[i][j]);
    return result;
}

SquareMat SquareMat::operator^(int power) const {
    if (power < 0) throw "Negative powers not supported.";
    SquareMat result(size);
    SquareMat base(*this);
    for (int i = 0; i < size; ++i)
        result[i][i] = 1;
    for (int p = 0; p < power; ++p)
        result = result * base;
    return result;
}


SquareMat& SquareMat::operator+=(const SquareMat& other) { return *this = *this + other; }
SquareMat& SquareMat::operator-=(const SquareMat& other) { return *this = *this - other; }
SquareMat& SquareMat::operator*=(const SquareMat& other) { return *this = *this * other; }
SquareMat& SquareMat::operator*=(double scalar) { return *this = *this * scalar; }
SquareMat& SquareMat::operator/=(double scalar) { return *this = *this / scalar; }
SquareMat& SquareMat::operator%=(int scalar) { return *this = *this % scalar; }
SquareMat& SquareMat::operator%=(const SquareMat& other) { return *this = *this % other; }


SquareMat SquareMat::operator-() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = -data[i][j];
    return result;
}

SquareMat SquareMat::operator~() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[j][i];
    return result;
}

double SquareMat::operator!() const {
    if (size == 1) return data[0][0];
    if (size == 2) return data[0][0]*data[1][1] - data[0][1]*data[1][0];
    if (size == 3) {
        return data[0][0]*(data[1][1]*data[2][2] - data[1][2]*data[2][1]) -
               data[0][1]*(data[1][0]*data[2][2] - data[1][2]*data[2][0]) +
               data[0][2]*(data[1][0]*data[2][1] - data[1][1]*data[2][0]);
    }
    throw "Determinant not implemented for size > 3.";
}


bool SquareMat::operator==(const SquareMat& other) const { return sum() == other.sum(); }
bool SquareMat::operator!=(const SquareMat& other) const { return !(*this == other); }
bool SquareMat::operator<(const SquareMat& other) const { return sum() < other.sum(); }
bool SquareMat::operator>(const SquareMat& other) const { return sum() > other.sum(); }
bool SquareMat::operator<=(const SquareMat& other) const { return sum() <= other.sum(); }
bool SquareMat::operator>=(const SquareMat& other) const { return sum() >= other.sum(); }


std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j)
            os << mat.data[i][j] << " ";
        os << "\n";
    }
    return os;
}

SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ++data[i][j];
        }
    }
    return *this;
}


SquareMat SquareMat::operator++(int) {
    SquareMat temp(*this);
    ++(*this);
    return temp;
}


SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            --data[i][j];
        }
    }
    return *this;
}


SquareMat SquareMat::operator--(int) {
    SquareMat temp(*this);
    --(*this);
    return temp;
}



} 
