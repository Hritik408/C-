#include <iostream>
#include <vector>
// find path from root to k to root

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


void Preorder(node *root)
{
    if (root != nullptr)
    {
        std::cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}


bool path(node *root, std::vector<int> &p, int k)
{
    if (root == nullptr)
        return false;

    if (root->data == k)
    {
        p.push_back(root->data);
        return true;
    }
    if (path(root->left, p, k) || path(root->right, p, k))
    {
        p.push_back(root->data);
        return true;
    }

    return false;
}

int main()
{
    node *root = nullptr;

    std::vector<int> P;

    root = insert(root, 20);
    insert(root, 18);
    insert(root, 15);
    insert(root, 27);
    insert(root, 12);
    insert(root, 19);
    insert(root, 13);

    int k = 15;

    bool ans = path(root, P, k);

    std::cout << std::boolalpha << ans << std::endl;

    std::cout<< "\nPreorder traversals: ";
    Preorder(root);

    // print the path

    if (ans)
    {
        std::cout << "\nPath from root to " << k << ": ";
        for (int i = P.size() - 1; i >= 0; --i)
        {
            std::cout << P[i] << " ";
        }
    }

    return 0;
}