#include <iostream>
#include <cassert>
#include "queue.h"

/////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION
/////////////////////////////////////////////////////////////////////////////

Queue::Queue() : first(nullptr), last(nullptr) {
  
}

void Queue::enqueue(int value) {
  
  if (first == nullptr) { // Case 1: empty list
    first = new Node(value, nullptr);
  } else { // Case 2: non-empty list (code as before)
    Node* temp = new Node(value, first);
    first = temp;
  }

}

int Queue::dequeue() {
  // check if empty
  if (is_empty()) {
    return 1;
  }
  first = first->next;
  
  return 0;
}

bool Queue::is_empty() const {
  if (first != nullptr && last != nullptr) {
    return true;
  }
  return false;
}

void Queue::print_reverse() const {
  // TODO
}

// PRE: -
// POST: print the sequence of integers in nodes reachable from n,
//       in order, with one space before each integer.
void print_node(Node* n) {
  if (n != nullptr) {
    std::cout << " " << n->value;
    print_node(n->next);
  }
}


void Queue::print() const {
  std::cout << "[";
  if (first != nullptr) {
    std::cout << first->value;
    print_node(first->next);
  }
  std::cout << "]";
}
