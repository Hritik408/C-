#include <iostream>

struct node {
    int data;
    node* left;
    node* right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};


node* insert(node* root, int value) {
    if (root == nullptr) {
        return new node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}


void inorder(node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}


node* pred(node* root) {
    root = root->left;
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}


node* deleteNode(node* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
     else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 

    else {  // here i find the target node
        if (root->left == nullptr && root->right == nullptr) {
           delete root;
            return nullptr;
        } 
        else if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        } 
        else {
            node* temp = pred(root);   
            root->data = temp->data;  // here we replace the current node with its precedessor
            root->left = deleteNode(root->left, temp->data);
        }
    }
    return root;
}


int main() {
    node* root = insert(nullptr, 20);
    for (int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
        insert(root, value);

    std::cout << "In-order traversal before deletion: ";
    inorder(root);
    std::cout << std::endl;

    int key = 15;

    root = deleteNode(root, key);

    std::cout << "\nIn-order traversal after deletion of " << key << ": ";
    inorder(root);
    std::cout << std::endl;

    return 0;
}