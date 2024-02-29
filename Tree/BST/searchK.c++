#include <iostream>
#include <climits>
#include <algorithm>

struct node
{
    int data;
    node *left;
    node *right;

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


void inorder(node* root){
    if(root == nullptr) return;

      if(root != nullptr){
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
}


bool search(node* root, int key){
   // if(root == nullptr) return false;

    while (root != nullptr)
    {
        if(root->data == key) return true;

        if(root->data < key)   root = root->right;
        else   root = root->left;
    }
    return false;
    
}


int floar(node* root, int key){
    int ans = INT_MIN;
    
    while(root != nullptr){
        if(root->data <= key){
            ans = root->data;
            root = root->right;
        } 
        else root = root->left;
    }
    return ans;
}


int main(){
    node* root = insert(nullptr, 8);
    for(int value : {4, 1, 7, 6, 13, 15, 17, 10})
    insert(root, value);

    int key = 3;

  bool ans = search(root, key);

  std::cout << std::boolalpha <<  ans;

  int sol = floar(root, key);

  std::cout << sol;

  return 0;
}