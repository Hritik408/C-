#include <iostream>
#include <cstdlib>
// find the longest path between any two node

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

// Function to find the diameter of the binary tree
int diameter(node *root, int &ans)
{
    if (root == nullptr)
        return -1;

    // Recursively calculate the heights of the left and right subtrees
    int leftHeight = diameter(root->left, ans);
    int rightHeight = diameter(root->right, ans);

    // Update the diameter if the sum of left and right heights + 2 is greater
    ans = std::max(ans, leftHeight + rightHeight + 2);

    // Return the height of the current subtree node
    return std::max(leftHeight, rightHeight) + 1;


}

int main()
{
   node *root = insert(nullptr, 20);
for (int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
    insert(root, value);

    int ans = 0;
    diameter(root, ans);

    std::cout << "Diameter of the binary tree: " << ans << std::endl;

    // Don't forget to free memory
    // Add a function to delete the tree nodes
    // ...

    return 0;
}
