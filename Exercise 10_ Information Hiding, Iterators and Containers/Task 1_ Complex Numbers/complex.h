#pragma once

#include <iostream>
#include <cmath>

// complex number struct
struct Complex {
  double a;
  double b;
};


// prints a complex number in format a + bi
std::ostream& operator<<(std::ostream& out, Complex& z);

// reads a complex number from input
std::istream& operator>>(std::istream& in, Complex& z);

// addition
Complex operator+(const Complex z1, const Complex z2);

Complex operator-(const Complex z1, const Complex z2);

Complex operator*(const Complex z1, const Complex z2);

Complex operator/(const Complex z1, const Complex z2);

// negation
Complex operator-(const Complex z1);

bool operator==(const Complex z1, const Complex z2);
bool operator!=(const Complex z1, const Complex z2);
