#include "node.h"

// Constructor
Node::Node(int v, Node* l, Node* r) : value(v), left(l), right(r) {}

// Destructor
Node::~Node() {
    // Recursively delete the left and right children
    delete left;
    delete right;
}
