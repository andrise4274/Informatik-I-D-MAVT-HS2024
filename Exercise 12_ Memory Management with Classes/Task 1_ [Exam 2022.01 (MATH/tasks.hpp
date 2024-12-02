#pragma once

#include <cassert>
#include "CircularLinkedList.hpp"



// PRE: value > 0
// POST: insert a new Node containing the value at the beginning of the list
void CircularLinkedList::insertAtBegin(int value) {
  assert(value > 0);
  Node * new_node = new Node(value);
  Node * old_next = sentinel->next;
  sentinel->next = new_node;
  new_node->next = old_next;
}

// PRE: value > 0
// POST: insert a new Node containing the value at the end of the list
void CircularLinkedList::insertAtEnd(int value) {
  assert(value > 0);
  // loop through linked list
  Node * n = sentinel->next;
  if (n == sentinel){
    Node * new_node = new Node(value);
    new_node->next = sentinel;
    sentinel->next = new_node;
    return;
  }
  for(; n->next != sentinel; n = n->next);
  Node * new_node = new Node(value);
  new_node->next = sentinel;
  n->next = new_node;
}

// PRE: value > 0
// POST: removes *all* the nodes with the provided value from the list
//       and deallocates the memory of the deleted nodes.
void CircularLinkedList::removeValues(int value) {
  assert(value > 0);
  Node * n_min1 = sentinel;
  Node * n = sentinel->next;
   while (n != sentinel) {
    if (n->value == value) {
      n_min1->next = n->next;
      delete n;
      n = n_min1->next;
    } else {
      n_min1 = n_min1->next;
      n = n->next;
    }
  }
}

// POST: Deconstructs the whole list, which includes deallocating 
//       all its nodes and the sentinel
CircularLinkedList::~CircularLinkedList() {
  Node * n = sentinel->next;
  
  while (n != sentinel) {
    Node * to_delete = n;
    n = n->next;
    delete to_delete;
  }
  delete sentinel;
}
