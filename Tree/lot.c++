#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
// level order traversals from left to right
// in this question nullptr is used because we want to come to the new line

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


 void lot(node *root){

    if(root == nullptr)  return;
    
      std::queue<node *> q;
    
    q.push(root);
    q.push(nullptr);

    while (q.size() > 1)
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr)  // temp nullptr aane se phle all the previous left and right elements of root placed in the queue
        {
            if (!q.empty())    q.push(nullptr);
           std::cout << std::endl;  // come to next line
            continue;  // that means goes to the while loop
        }

     std::cout << temp->data << " ";
        
        
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
        // for right to left, reverse the above if conditions
    }
 }


int main()
{
    node *root = insert(nullptr, 20);
for (int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
    insert(root, value);

    lot(root);
   
    return 0;
}