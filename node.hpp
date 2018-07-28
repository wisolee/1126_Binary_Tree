#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <cstdlib>

class node {
    public:
        int data;
        node* left;
        node* right;

        // Constructor
        node(int data);
};

#endif