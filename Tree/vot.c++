#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <vector>

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

void vot(node *root)
{
    if (root == nullptr)
        return;

    std::unordered_map<int, std::vector<node *>> hm;
    std::queue<std::pair<node *, int>> q;

    int max_level = -1;
    int min_level = 1;

    q.push({root, 0});

    while (q.size() > 0)
    {
        std::pair<node *, int> temp = q.front();
        q.pop();


        node *current = temp.first;
        int level = temp.second;

        max_level = std::max(level, max_level);
        min_level = std::min(level, min_level);

        hm[level].push_back(current);

        if (current->left != nullptr)
            q.push({current->left, level - 1});
        if (current->right != nullptr)
            q.push({current->right, level + 1});
    }

    std::cout << "Vertical level order traversals" << std::endl;

    for (int i = min_level; i <= max_level; i++)
    {
        std::vector<node *> temp = hm[i];

        for (int j = 0; j < temp.size(); ++j)
        {
            std::cout << temp[j]->data << " ";
        }
        std::cout << std::endl;
    }

      std::cout << "\nTop view of tree" << std::endl;

    for (int i = min_level; i <= max_level; i++) {
        std::vector<node*> temp = hm[i];

        for (int j = 0; j < temp.size(); ++j)
        { 
         for(int k = 0; k < 1; k++){
            std::cout << temp[k]->data << " ";
         }
         break;
        }
    }

}

int main()
{
    node *root = insert(nullptr, 20);
    for (int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
        insert(root, value);

    vot(root);

    return 0;
}
