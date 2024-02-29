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

int maxPath(node *root, int &ans)
{
    if (root == nullptr)
        return 0;

    int l = maxPath(root->left, ans);  // max path starting form root->left
    int r = maxPath(root->right, ans); //  maximum path starting from root->right

    ans = std::max(ans, root->data + std::max(l, 0) + std::max(r, 0)); // maximum path containing the root

    return root->data + std::max(std::max(l, r), 0); // return maximum path if i start from root
}

int main()
{
    node *root = insert(nullptr, 20);
    for (int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
        insert(root, value);

    int ans = INT_MIN;

    maxPath(root, ans);

    std::cout << ans;

    return 0;
}