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


node* pred(node* root){
    node* temp = root->left;
    while(temp->right && temp->right != root)
    temp = temp->right;
    
    return temp;
}


void inorder(node* root) {
    node* curr = root;

    while (curr) {
        if (curr->left == nullptr) {
            std::cout << curr->data << " ";
            curr = curr->right;
        }
         else {
            
            node* temp = pred(curr);

            if (temp->right == nullptr) {  // if link is not made then made and move to left
                temp->right = curr;
                curr = curr->left;
            }
             else {                      // if link is already make then print the item and move to right 
                temp->right = nullptr;
                std::cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main() {
    node* root = insert(nullptr, 20);
    for (int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
        insert(root, value);

    std::cout << "In-order traversal using Morris Traversal: ";
    inorder(root);

    return 0;
}
