#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
};

node *
newNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = nullptr;

    return temp;
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

int main()
{
    node *root = newNode(20);
    root->left = newNode(22);
    root->right = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    inorder(root);

    return 0;
}
