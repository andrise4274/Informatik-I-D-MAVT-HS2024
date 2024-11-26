#include <iostream>
#include <cassert>
#include "queue.h"

/////////////////////////////////////////////////////////////////////////////
// recursive helper function
void print_element_after(Node *n);
/////////////////////////////////////////////////////////////////////////////

Queue::Queue() : first(nullptr), last(nullptr) {}


void Queue::enqueue(int value) {
  Node* new_node = new Node(value, nullptr);
  // if the list is empty, set first AND last to pointer to new_node
  if (first == nullptr) {
    first = new_node;
    last = new_node;
  // if list isn't empty - let current last to point to new_node, 
  //set last pointer to new_node
  } else { 
    last->next = new_node;
    last = new_node;
  }

}

int Queue::dequeue() {
  // check if empty
  if (is_empty()) {
    return 1;
  }
  Node *node_to_remove = first;
  // set the beginning of linked list to 2nd element
  first = first->next;
  // if list is empty now, ensure last is nullptr too
  if (first == nullptr) {
    last = nullptr;
  }
  // get the return value
  int val = node_to_remove->value;
  // free allocated memory of deleted node (similar to malloc() and free() in C)
  // memory was allocated in enqueue function with new keyword
  delete node_to_remove;
  return val;
}


bool Queue::is_empty() const {
  if (first == nullptr) {
    return true;
  }
  return false;
}


void Queue::print_reverse() const {
  std::cout << "[";
  // recursive call
  if (first != nullptr) {
    print_element_after(first);
  }
  std::cout << "]" << std::endl;
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


// recursive helper function
// PRE: takes a pointer to Node
// POST: prints all values of Nodes which come after Node
void print_element_after(Node *n) {
  if (n->next != nullptr) {
    // recursive call
    print_element_after(n->next);
    std::cout << " " << n->value;
  } else {
    std::cout << n->value;
  }
}
