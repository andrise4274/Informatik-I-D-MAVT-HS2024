// PRE: x >= 0
// POST: returns n to the power of x
int f1(int n, int x) {
  int res = 1;
  for (; x > 0; x--) {
    res *= n;
  }
  return res;
}

// PRE: n >= 0
// POST: returns the number of digits of n
int f2(int n) {
  int i = 0;
  while (n > 0) {
    n = n / 10;
    ++i;
  }
  return i;
}

// PRE:  n > 1
// POST: returns if n is a prime number
bool f3(int n) {
  int i = 2;
  for (; n % i != 0; ++i);
  return n == i;
}

// PRE: n, positive number with sqrt(n) in Natural Numbers
// POST: returns the smallest int i, which i * i = n
int f4(int n) {
  int i = 0;
  while (i * i != n) {
    ++i;
  }
  return i;
}
