#include <iostream>
#include <climits>
#include <algorithm>
// it is range method from which we check it is bst or not

struct node{
    int data;
    node* left;
    node* right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};



node* insert(node* root, int value){
    if(root == nullptr) return new node(value);

    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else 
    root->right = insert(root->right, value);
    
    return root;
}


node* trim(node* root, int l, int r){
    if(root == nullptr )  return nullptr;

    if(l <= root->data && root->data <= r){
     root->left = trim(root->left, l, r);
     root->right = trim(root->right, l, r);
     return root;
    }
    else if(root->data < l) 
    trim(root->right, l, r);
    else
    trim(root->left, l, r);

}

void inorder(node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

int main(){
    node* root = insert(nullptr, 10);

    for(int value : {5, 15, 3, 7, 14, 9, 13, 20})
    insert(root, value);
    inorder(root);
    std::cout << std::endl;

    // std::cout<< trim(root, 7, 15);
    trim(root, 7, 15);

    inorder(root);
     

    return 0;
}