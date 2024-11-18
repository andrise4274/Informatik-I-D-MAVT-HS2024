#include <iostream>

int main() {
  // input of r_1, r_2, r_3 and r_4
  int r_1, r_2, r_3, r_4 = 0;
  std::cin >> r_1;
  std::cin >> r_2;
  std::cin >> r_3;
  std::cin >> r_4;
  
  // calculate series resistances
  int r_12 = r_1 + r_2;
  int r_34 = r_3 + r_4;
  //check if one branch has R=0, and return 0 in this case
  if (r_12 == 0 || r_34 == 0) {
    std::cout << 0;
    return 0;
  }
  
  // calculate total parallel resustance with R = R_1 * R_2 / (R_1 + R_2)
  int eq_r = 0;
  eq_r = r_12 * r_34;
  
  // calculate rounding bias
  int rest = eq_r % (r_12 + r_34);
  int r_factor = 0;
  // check if rest / (r_12 + r_34) is bigger than 0.5
  if (2 * rest >= (r_12 + r_34)) {
    r_factor = 1;
  }
  
  // output rounded answer
  std::cout << (eq_r - rest) / (r_12 + r_34) + r_factor;
  return 0;
}