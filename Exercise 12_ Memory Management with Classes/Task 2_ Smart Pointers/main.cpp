#include <iostream>
#include <vector>
#include <cassert>
#include "smart.h"
#include "tracker.h"


// Minimal functionality test for smart pointers.
// Everything should be properly deallocated at the end.
void minimal() {
  Smart n = Smart();
  // how many Smart object share the same ptr?
  std::cout << n.get_count() << "\n";

  Smart n_arg = Smart(nullptr);
  // how many Smart object share the same ptr?
  std::cout << n.get_count() << "\n";

  Smart a = Smart(new tracked());
  a->next() = Smart(new tracked());
  Smart b = Smart(a->next());
}


// POST: Swap v pseudo-randomly to make the deallocation order arbitrary.
void shuffle(std::vector<Smart>& v) {
  const int sz = v.size();
  for (int i = 0; i != sz; ++i) {
    std::swap(v[(i * i) % sz], v[(i * i * i) % sz]);
    std::swap(v[i], v[(i * i + i) % sz]);
  }
}

// POST: asserts that every node in v point to a node with smaller value.
void sorted_nodes(std::vector<Smart>& v) {
  for (int i = 0; i != int(v.size()); ++i) {
    if(v[i] != Smart() && v[i]->next() != Smart()) {
      assert(v[i]->value() > v[i]->next()->value());
    }
  }
}

// Test: create a linked-list structure where each node may be pointed by
//       two elements (structure is shared)
//       everything should be properly deallocated at the end.
void binary_cactus(int n) {
  std::vector<Smart> v = std::vector<Smart>();
  v.push_back(Smart());
  for (int i = 1; i <= n; ++i) {
    v.push_back(Smart(new tracked()));
    v[i]->value() = i;
    v[i]->next() = v[(i - 1) / 2];
  }
  shuffle(v);
  sorted_nodes(v);
}

// Test: create a pseudo-random linked list structure where some
//       nodes are more likely to be used than others.
//       everything should be properly deallocated at the end.
void popular_nodes(int n) {
  std::vector<Smart> v = std::vector<Smart>(n);
  for (int i = 1; i < n; ++i) {
    v[i] = Smart(new tracked());
    int j = n % i;
    j = (j * j) % i;
    j = (j * j) % i;
    if (j % 4 == 0) {
        if (2 * i > n) {
            j = n / 2;
        } else {
            j = j % 3;
        }
    }
    v[i]->value() = i;
    v[i]->next() = v[j];
  }
  shuffle(v);
  sorted_nodes(v);
}

// Test: create a spiraling structure.
//       Everything but n nodes should be deallocated at the end.
void spiral(int n, int rounds) {
  std::vector<Smart> v = std::vector<Smart>(n * (rounds + 1));
  for (int i = 0; i != int(v.size()); ++i) {
    v[i] = Smart(new tracked());
    v[i]->value() =  i;
  }
  for (int i = 0; i != int(v.size()) ;++i) {
    int j = i + 1;
    if(j >= n) {
      j -= n;
    }
    v[i]->next() = v[(i + 1) % n];
  }
  shuffle(v);
}

void implicit_delete() {
  Smart a = Smart(new tracked());
  Smart b = Smart(new tracked());
  a = b;
}


int main() {
  int test_id;
  std::cin >> test_id;
  
  // The scopes inside different cases prevent multiple
  // declarations of size in the same scope
  switch(test_id) {
  case 0:
    minimal();
    break;
  case 1:
    {
      int size;
      std::cin >> size;
      binary_cactus(size);
    }
    break;
  case 2:
    {
      int size;
      std::cin >> size;
      popular_nodes(size);
    }
    break;
  case 3:
    {
      int n;
      int rounds;
      std::cin >> n;
      std::cin >> rounds;
      spiral(n, rounds);
    }
    break;
  case 4:
    implicit_delete();
    break;
  default:
    your_own_tests();
  }
  std::cout << "Remaining objects of class tracked: " << count_tracked() << '\n';
  return 0;
}
