#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <cstdlib>
#include <queue>

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
        int get_count(node* root);
        int get_max(node* root);
        int get_min(node* root);
        
        // Update Methods
        void set_root(node* new_root);

        // Manipulator Methods
        //void insert(int data); <-- loop version
        node* insert(node* root, int data);
        node* remove(node* root, int data);
        bool search(node* root, int data);

        // Breadth-First Search Algorithm
        void print_levelorder(node* root);
        // Depth-First Search Algorithms
        void print_inorder(node* root);
        void print_preorder(node* root);
        void print_postorder(node* root);

};

#endif