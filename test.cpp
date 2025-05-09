//souldaher210@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"

using namespace matlib;

TEST_CASE("Constructor and access") {
    SquareMat m(2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 3;
    m[1][1] = 4;

    CHECK(m[0][0] == 1);
    CHECK(m[1][1] == 4);
}

TEST_CASE("Addition and subtraction") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    SquareMat c = a + b;
    CHECK(c[0][0] == 6);
    CHECK(c[1][1] == 12);

    SquareMat d = b - a;
    CHECK(d[0][0] == 4);
    CHECK(d[1][1] == 4);
}

TEST_CASE("Multiplication (matrix * matrix and scalar)") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    b[0][0] = 2; b[0][1] = 0;
    b[1][0] = 1; b[1][1] = 2;

    SquareMat c = a * b;
    CHECK(c[0][0] == 4);
    CHECK(c[0][1] == 4);
    CHECK(c[1][0] == 10);
    CHECK(c[1][1] == 8);

    SquareMat d = a * 2.0;
    CHECK(d[1][1] == 8);
}

TEST_CASE("Scalar division and modulo") {
    SquareMat m(2);
    m[0][0] = 4; m[0][1] = 6;
    m[1][0] = 8; m[1][1] = 10;

    SquareMat d = m / 2.0;
    CHECK(d[0][0] == 2);
    CHECK(d[1][1] == 5);

    SquareMat r = m % 3;
    CHECK(r[0][0] == 1);
    CHECK(r[1][1] == 1);
}

TEST_CASE("Unary and transpose") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    SquareMat neg = -m;
    CHECK(neg[0][0] == -1);
    CHECK(neg[1][1] == -4);

    SquareMat t = ~m;
    CHECK(t[0][1] == 3);
    CHECK(t[1][0] == 2);
}

TEST_CASE("Determinant") {
    SquareMat m2(2);
    m2[0][0] = 1; m2[0][1] = 2;
    m2[1][0] = 3; m2[1][1] = 4;

    CHECK(!m2 == doctest::Approx(-2.0));

    SquareMat m3(3);
    m3[0][0] = 6; m3[0][1] = 1; m3[0][2] = 1;
    m3[1][0] = 4; m3[1][1] = -2; m3[1][2] = 5;
    m3[2][0] = 2; m3[2][1] = 8; m3[2][2] = 7;

    CHECK(!m3 == doctest::Approx(-306.0));
}

TEST_CASE("Comparison operators") {
    SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 1;
    a[1][0] = 1; a[1][1] = 1;

    b[0][0] = 2; b[0][1] = 2;
    b[1][0] = 2; b[1][1] = 2;

    CHECK(a != b);
    CHECK(b > a);
    CHECK(a < b);
}

TEST_CASE("Power operator") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 1;
    m[1][0] = 1; m[1][1] = 0;

    SquareMat m2 = m ^ 2;
    CHECK(m2[0][0] == 2);
    CHECK(m2[0][1] == 1);
    CHECK(m2[1][0] == 1);
    CHECK(m2[1][1] == 1);
}

TEST_CASE("Increment and decrement") {
    SquareMat m(2);
    m[0][0] = 1; m[0][1] = 2;
    m[1][0] = 3; m[1][1] = 4;

    SquareMat post = m++;
    CHECK(post[0][0] == 1);
    CHECK(m[0][0] == 2);

    SquareMat pre = ++m;
    CHECK(pre[0][0] == 3);
    CHECK(m[0][0] == 3);

    m--;
    CHECK(m[0][0] == 2);

    --m;
    CHECK(m[0][0] == 1);
}
