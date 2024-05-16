#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
//

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

int main()
{

    node *root = insert(nullptr, 20);
for (int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
    insert(root, value);


    std::queue<node *> q;
    std::vector<std::vector<int>> v;
    std::vector<int> level;
    
    q.push(root);
    q.push(nullptr);

    while (q.size() > 1)
    {
        node *temp = q.front();
        q.pop();

        v.push_back(level);
        level.clear();

        if (temp == nullptr)
        {
            if (!q.empty())   q.push(nullptr);
           continue;
        }

     level.push_back(temp->data);
        

        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }

       for (const auto &level : v)
{
    for (int data : level)
    {
        std::cout << data << " ";
    }
    std::cout << std::endl;
}

    return 0;
}

