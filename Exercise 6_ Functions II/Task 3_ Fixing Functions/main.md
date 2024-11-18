Please write your solution here.
For your convenience we have added a template for your answers below.

# Function  `c++|is_even`:

The problem with this function is, that the if statement can be neglected, for a more compact code.

```c++
// PRE: n/a
// POST: returns true if n is even, false otherwise
bool is_even(int i) {
  return (i % 2 == 0);
}
```

# Function `c++|invert`:

The problem with this function is that if the input is 0, the returned variable result has no value assigned to it. -> use assert();

```c++
// PRE: x ¬ 0
// POST: returns 1/x
double invert(int x) {
  double result;
  assert( x != 0);
  return 1.0 / x;
}
```