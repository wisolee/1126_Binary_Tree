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

    // std::cout << "Tree contains " << tree->get_count(tree->get_root()) << " nodes.\n";
    // tree->print_inorder(tree->get_root());
    // std::cout << std::endl;
    // tree->print_levelorder(tree->get_root());
    // std::cout << "The max in this tree is " << tree->get_max(tree->get_root()) << std::endl;
    // std::cout << "The min in this tree is " << tree->get_min(tree->get_root()) << std::endl;

    for (int i = 0; i < size; i++) {
        node* new_root = tree->insert(tree->get_root(), i);
        tree->set_root(new_root);
    }
    tree->print_inorder(tree->get_root());
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        node* new_root = tree->remove(tree->get_root(), i);
        tree->set_root(new_root);
    }
    tree->print_inorder(tree->get_root());
    std::cout << std::endl;

    int number;
    char response;
    do {
        std::cout << "Enter a number to search for: ";
        std::cin >> number;
        if ( tree->search( tree->get_root(), number) ) {
            std::cout << "Value found.\n";
        } else {
            std::cout << "Value not found.\n";
        }
        std::cout << "Do you want to look up another value? (y/n): \n";
        std::cin >> response;
    } while(response == 'y');

    return 0;
}