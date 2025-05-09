# SquareMatProject

A C++ implementation of a square matrix class (`SquareMat`) that supports a variety of matrix operations without using the C++ standard library (except for `<iostream>` and `<cmath>`). The project also includes a suite of tests using the Doctest framework.

## Features

- Creation and destruction of dynamic square matrices.
- Copy constructor and assignment operator (Rule of Three).
- Arithmetic operations: `+`, `-`, `*`, scalar multiplication, division, modulo.
- Comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=`.
- Unary operations: negation, increment/decrement (`++`, `--`), transpose (`~`), determinant (`!`).
- Accessor methods: `setData`, `getData`, `getSize`.
- Index operator: `[][]`-like access via `operator[]`.
- Power operator: `^` for raising a matrix to an integer power.
- Stream output (`<<`) for pretty-printing matrices.

## Project Structure
├── SquareMat.hpp # Matrix class definition
├── SquareMat.cpp # Matrix class implementation
├── Main.cpp # Entry point (optional)
├── test.cpp # Doctest unit tests
├──doctest.h #header-only framework
├── makefile # Build system
└── README.md # This file


## Compilation

Make sure you have `g++` installed.

```bash
make test
