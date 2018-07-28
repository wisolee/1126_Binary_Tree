#include "binary_tree.hpp"

binary_tree::binary_tree() {
    this->root = nullptr;
}

node* binary_tree::get_root() {
    return this->root;
}

void binary_tree::insert(int data) {
    node* inserted_node = new node(data);
    if (this->root == nullptr) {        // Case 1: tree is empty
        this->root = inserted_node;
    } else {                            // Case 2: tree is not empty
        node* parent = nullptr;
        node* child = this->root;
        while (child != nullptr) {
            parent = child;
            child = ( data < parent->data ? child->left : child->right );
        }
        if (data < parent->data) {
            parent->left = inserted_node;
        } else {
            parent->right = inserted_node;
        }
    }

    return;
}

void binary_tree::print_inorder(node* root) {
    node* curr_node = root;
    if (curr_node == nullptr) return; // base/terminating case

    print_inorder(curr_node->left);
    std::cout << curr_node->data << " ";
    print_inorder(curr_node->right);
}

void binary_tree::print_preorder(node* root) {
    node* curr_node = root;
    if (curr_node == nullptr) return; // base/terminating case

    std::cout << curr_node->data << " ";
    print_inorder(curr_node->left);
    print_inorder(curr_node->right);
}

void binary_tree::print_postorder(node* root) {
    node* curr_node = root;
    if (curr_node == nullptr) return; // base/terminating case

    print_inorder(curr_node->left);
    print_inorder(curr_node->right); 
    std::cout << curr_node->data << " ";
    
}