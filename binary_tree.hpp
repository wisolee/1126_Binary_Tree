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
        
        // Update Methods
        void set_root(node* new_root);

        // Member Methods
        //void insert(int data); <-- loop version
        node* insert(node* root, int data);
        bool search(node* root, int data);

        void print_inorder(node* root);
        void print_preorder(node* root);
        void print_postorder(node* root);

};

#endif