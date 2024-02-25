#include <iostream>
// count all nodes which are k distance from root

struct node
{
    int data;
    node *left;
    node *right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};


node *insert(node *root, int value)
{
    if (root == nullptr)
        return new node(value);

    if (rand() % 2 == 0)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

int count(node *root, int k){
    if(root == nullptr) return 0;

    if(k==0) return 1;

    int lst = count(root->left, k-1);
    int rst = count(root->right, k-1);

    return lst + rst;
} 


int main()
{

   node *root = insert(nullptr, 20);
for (int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
    insert(root, value);

    int k = 3;

    int ans = count(root, k);

   std::cout<< ans ;

    return 0;
}