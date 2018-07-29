#include <iostream>
#include <cstdlib>

#include "binary_tree.hpp"

int main (int argc, char* argv[]) {
    binary_tree* tree = new binary_tree();
    std::cout << "Choose a the number of nodes: ";
    int size;
    std::cin >> size;
    std::cout << "Enter " << size << " values: ";
    int value;
    for (int i = 0; i < size; i++) {
        std::cin >> value;
        node* new_root = nullptr;
        new_root = tree->insert(tree->get_root(), value);
        tree->set_root(new_root);
    }

    tree->print_inorder(tree->get_root());
    std::cout << std::endl;
    // tree->print_preorder(tree->get_root());
    // std::cout << std::endl;
    // tree->print_postorder(tree->get_root());
    // std::cout << std::endl;
    return 0;
}