
#include "binary_tree.hpp"

// Constructor: Creates an empty binary tree
binary_tree::binary_tree() {
    this->root = nullptr;
}

// Retrieves root
node* binary_tree::get_root() {
    return this->root;
}

// Retrieves count (number of nodes in tree)
int binary_tree::get_count(node* root) {
    if (root == nullptr) {
        return 0;
    }
    return get_count(root->left) + get_count(root->right) + 1;
}

// Updates root
void binary_tree::set_root(node* new_root) {
    this->root = new_root;
}

// Loop version of insert
// void binary_tree::insert(int data) {
//     node* inserted_node = new node(data);
//     if (this->root == nullptr) {        // Case 1: tree is empty
//         this->root = inserted_node;
//     } else {                            // Case 2: tree is not empty
//         node* parent = nullptr;
//         node* child = this->root;
//         while (child != nullptr) {
//             parent = child;
//             child = ( data < parent->data ? child->left : child->right );
//         }
//         if (data < parent->data) {
//             parent->left = inserted_node;
//         } else {
//             parent->right = inserted_node;
//         }
//     }

//     return;
// }

node* binary_tree::insert(node* root, int data) {
    // Case 1: Tree is empty
    if (root == nullptr) {
        root = new node(data);
    } else if (data <= root->data) {                // Case 2.1: Insert into left subtree
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);    // Case 2.2: Insert into right subtree
    }

    return root;
}

bool binary_tree::search(node* root, int data) {
    // Case 1: Tree is empty
    if (root == nullptr) {
        return false;
    } else if (data == root->data) {
        return true;
    } else if (data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }

    return false;
}

void binary_tree::print_levelorder(node* root) {
    // Case 1: Tree is empty
    if (root == nullptr) {
        return;
    }
    // Case 2: Tree is not empty
    std::queue<node*> discovery_queue;
    discovery_queue.push(root);
    while (!discovery_queue.empty()) {
        // Push children of discovered node
        node* popped_node = discovery_queue.front();
        if (popped_node->left != nullptr) discovery_queue.push(popped_node->left);
        if (popped_node->right != nullptr) discovery_queue.push(popped_node->right);
        std::cout << popped_node->data << " ";
        discovery_queue.pop();
    }
    std::cout << std::endl;
    return;
}

void binary_tree::print_inorder(node* root) {
    node* curr_node = root;
    if (curr_node == nullptr) return; // base/terminating case

    print_inorder(curr_node->left);
    std::cout << curr_node->data << " ";
    print_inorder(curr_node->right);
    return;
}

void binary_tree::print_preorder(node* root) {
    node* curr_node = root;
    if (curr_node == nullptr) return; // base/terminating case

    std::cout << curr_node->data << " ";
    print_inorder(curr_node->left);
    print_inorder(curr_node->right);
    return;
}

void binary_tree::print_postorder(node* root) {
    node* curr_node = root;
    if (curr_node == nullptr) return; // base/terminating case

    print_inorder(curr_node->left);
    print_inorder(curr_node->right); 
    std::cout << curr_node->data << " ";
    return;
    
}