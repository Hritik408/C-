#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
// left or right view of the tree

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

      bool first_node = false;
    
    q.push(root);
    q.push(nullptr);

    while (q.size() > 1)
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            if (!q.empty())   q.push(nullptr);
           std::cout << std::endl;  // come to next line
           first_node = false;
            continue;
        }
      
      if(!first_node){   // if statement will run if first_node will false
     std::cout << temp->data << " ";
        first_node = true;
      }
        
        
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
        // for right to left, reverse the above if condition
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