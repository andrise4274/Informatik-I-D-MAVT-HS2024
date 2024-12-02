#include "sorted_list.h"

// post: add a new node with value to the sorted linked list
//       several nodes with the same value are possible
void sorted_list::add(int value){
  // this creates a new node in dynamic memory, wrapped in a shared pointer
  // analogously to new node(value) for normal pointers
  node_ptr newNode = std::make_shared<node>(value); 

  node_ptr prev = nullptr;
  node_ptr n = first;
  while (n != nullptr && n->value < value){
    prev = n;
    n = n->next;
  }
  // if list is empty, only contains first element
  if (prev == nullptr){
    // if empty
    newNode->next = first;
    first = newNode;
  } else {
    // insert
    prev->next = newNode;
    newNode->next = n;
  }
}

// post: remove the first node which holds 'value', if any.
//       if there is no such node, return false
//       otherwise return true
bool sorted_list::remove(int value){
  node_ptr prev = nullptr;
  node_ptr n = first;
  while (n != nullptr && n->value < value){
    prev = n;
    n = n->next;
  }
  // ensure to avoid dereferencing a null pointer
  if (n != nullptr && n->value == value) {
    // if contains only one element;
    if (prev == nullptr) {
      first = n->next;
      return true;
    } else {
      prev->next = n->next;
      return true;
    }
  }
  return false;
}