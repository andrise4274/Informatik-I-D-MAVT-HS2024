#include <iostream>

int main()
{
  int a;
  std::cout << "input an integer \n: ";
  std::cin >> a;
  int a4 = a + a;
  a4= a4 + a4;
  int a8 = a4 + a4;
  int a16 = a8 + a8;
  std::cout << "29 x " << a << " = " << a + a4 + a8 + a16;
  
  // same idea, but with bit shifts
  // a << b => a * 2^b
  std::cout << " ---- bitshift version: 29 x " << a << " = " << a + (a << 2) + (a << 3) + (a << 4);
  
  return 0;
}