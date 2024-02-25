#include <iostream>
#include <climits>

struct node
{
    int data;
    node *left;
    node *right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void inorder(node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

void Preorder(node *root)
{
    if (root != nullptr)
    {
        std::cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(node *root)
{
    if (root != nullptr)
    {
        Postorder(root->left);
        Postorder(root->right);
        std::cout << root->data << " ";
    }
}


node *insert(node *root, int value)
{
    if (root == nullptr)    return new node(value);
    
    // if (value < root->data)  
    // root->left = insert(root->left, value);

    // else  
    // root->right = insert(root->right, value);

      if (rand() % 2 == 0) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int size(node *root){
    if(root == nullptr) return 0;
    int lst = size(root->left);
    int rst = size(root->right);
    return lst + rst + 1;
}

int findMax(node *root){
    if(root == nullptr) return INT_MIN;
    
    int lst = findMax(root->left);
    int rst = findMax(root->right);
    int maxi = std::max(std::max(rst,lst), root->data);

    return maxi;
}

 int findHeight(node *root){
    if(root == nullptr) return -1;

    int lst = findHeight(root->left);
    int rst = findHeight(root->right);
 
      return std::max(lst, rst) + 1;
 }
  

 int countLeaf(node *root){
    if(root == nullptr)  return 0;
    if(root->left == nullptr && root->right == nullptr) return 1;
    
    int lst = countLeaf(root->left);
    int rst = countLeaf(root->right);

    return lst+rst;
 }

int main()
{
    node *root = nullptr;

 root = insert(root, 20);
    insert(root, 18);
    insert(root, 15);
    insert(root, 27);
    insert(root, 12);
    insert(root, 19);
    insert(root, 10);
    insert(root, 24);
    insert(root, 30);
    insert(root, 7);
    insert(root, 1);
    insert(root, 11);
    insert(root, 29);
    insert(root, 35);
    insert(root, 5);
    insert(root, 13);
    insert(root, 33);

    std::cout<< "Inorder traversals: ";
    inorder(root);
    std::cout<< "\nPreorder traversals: ";
    Preorder(root);
    std::cout<< "\nPostorder traversals: ";
    Postorder(root);
    
    std::cout << std::endl;

    std::cout<< "\nSize of tree: ";
    std::cout<< size(root);

    std::cout<< "\nMax value of tree: ";
    std::cout<< findMax(root);

    std::cout<< "\nHeight of tree: ";
    std::cout<< findHeight(root);

    std::cout<< "\nNumber of leaf nodes in tree: ";
    std::cout<< countLeaf(root);

    return 0;
}

