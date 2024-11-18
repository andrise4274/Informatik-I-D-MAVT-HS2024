#include "complex.h"



std::istream& operator>>(std::istream& in, Complex& z) {
    char c; // separating characters '[', ',' and ']'
    return in >> c >> z.a >> c >> z.b >> c;
}


std::ostream& operator<<(std::ostream& out, Complex& z) {
  return out << "[" << z.a << "," << z.b << "]";
}

// plus operator
Complex operator+(const Complex z1, const Complex z2) {
  Complex result;
  result.a = z1.a + z2.a;
  result.b = z1.b + z2.b;
  return result;
}

// minus operator
Complex operator-(const Complex z1, const Complex z2) {
  Complex result;
  result.a = z1.a - z2.a;
  result.b = z1.b - z2.b;
  return result;
}

// mul operator
Complex operator*(const Complex z1, const Complex z2) {
  Complex result;
  result.a = z1.a * z2.a - z1.b * z2.b;
  result.b = z1.a * z2.b + z1.b * z2.a;
  return result;
}

// divison operator
Complex operator/(const Complex z1, const Complex z2) {
  Complex result;
  Complex conju;
  conju.a = z2.a;
  conju.b = - z2.b;
  double divisor = z2.a * z2.a + z2.b * z2.b;
  
  result = z1 * conju;
  result.a /= divisor;
  result.b /= divisor;
  return result;
}

// negation (overloading operator -)
Complex operator-(const Complex z1) {
  Complex result;
  result.a = - z1.a;
  result.b = - z1.b;
  return result;
}

// equality operator
bool operator==(const Complex z1, const Complex z2) {
  double eta = 0.0001;
  if (std::abs(z1.a - z2.a) < eta && std::abs(z1.b - z2.b) < eta) {
    return true;
  }
  return false;
}

// inequality operator
bool operator!=(const Complex z1, const Complex z2) {
  double eta = 0.0001;
  if (std::abs(z1.a - z2.a) < eta && std::abs(z1.b - z2.b) < eta) {
    return false;
  }
  return true;
}
