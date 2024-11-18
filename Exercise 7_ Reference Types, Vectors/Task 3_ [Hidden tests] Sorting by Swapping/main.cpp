#include <iostream>
// Enable vectors
#include <vector>


void bubble_sort(std::vector<int>& vec);
void print_vec(std::vector<int>& vec);

int main() {
    int length;
    std::cin >> length;
    
    if (length < 0) {
      std::cout << "The input must be a non-negative integer." << std::endl;
      return 1;
    }
    
    std::vector<int> values(length);
    
    // read integers in values vector
    for (int i = 0; i < length; i++) {
      std::cin >> values[i];
    }
    
    // sort values vector
    bubble_sort(values);
    
    // output
    print_vec(values);
    return 0;
}


// PRE: unsorted vector
// sorts original vector
void bubble_sort(std::vector<int>& vec) {
  // loop over vector
  for (int i = 0; i < int(vec.size()); i++) {
    // loop over vector a second time
    for (int j = 1; j < int(vec.size()) - i; j++) {
      // swap if j th value is bigger than jth + 1 value
      if (vec[j] > vec[j - 1]) {
        int temp = vec[j];
        vec[j] = vec[j - 1];
        vec[j - 1] = temp;
      }
    }
  }
}

void print_vec(std::vector<int>& vec) {
  for (int i = 0; i < int(vec.size()); i++) {
      std::cout << vec[i];
      std::cout << " ";
    }
}