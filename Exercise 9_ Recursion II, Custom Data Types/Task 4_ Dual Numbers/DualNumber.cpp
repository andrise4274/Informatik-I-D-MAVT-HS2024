#include "DualNumber.h"

DualNumber operator+(const DualNumber& dn1, const DualNumber& dn2) {
  DualNumber result = {0.0, 0.0};
  result.a = dn1.a + dn2.a;
  result.b = dn1.b + dn2.b;
  return result;
}

DualNumber operator-(const DualNumber& dn1, const DualNumber& dn2) {
  DualNumber result = {0.0, 0.0};
  result.a = dn1.a - dn2.a;
  result.b = dn1.b - dn2.b;
  return result;
}

DualNumber operator*(const DualNumber& dn1, const DualNumber& dn2) {
  DualNumber result = {0.0, 0.0};
  result.a = dn1.a * dn2.a;
  result.b = dn1.a * dn2.b + dn1.b * dn2.a;
  return result;
}