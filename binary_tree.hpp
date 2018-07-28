#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <cstdlib>

#include "node.hpp"

class binary_tree {
    private:
        node* root;

    public:
        // Constructor
        binary_tree();
        // Deconstructor
        // ~binary_tree();

        // Retrieval Methods
        node* get_root();

        // Member Methds
        void insert(int data);

        void print_inorder(node* root);
        void print_preorder(node* root);
        void print_postorder(node* root);

};

#endif