#pragma once

#include <memory>
#include <iostream>

struct node;
using node_ptr = std::shared_ptr<node>; // shared_ptr version of "node*"

struct node{
  node_ptr next; 
  int value;

  node(int v): next(nullptr), value(v) {}
};


class sorted_list{

  node_ptr first;
  
  public:
  
  // post: add a new node with value to the sorted linked list
  //       several nodes with the same value are possible
  void add(int value);

  // post: remove one node with value, if any
  //       if there is no such node, return false
  //       otherwise return true
  bool remove(int value);
  
  // post: output the linked list of nodes
  //       in the form 1->2->3->null
  void print(std::ostream& out){
    node_ptr n = first;
    while(n != nullptr){
      out << n->value << "->";
      n = n->next;
    }
    out << "null";
  }
};