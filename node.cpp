#include "node.hpp"

node::node(int data) {
    this->data = data;
    this->left = this->right = nullptr;
}