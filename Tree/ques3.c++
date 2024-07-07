#include <iostream>
#include <vector>
#include <algorithm>
// path between two nodes

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
   node *root = insert(nullptr, 20);
for (int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
    insert(root, value);

    int m = 5;  // here m and n are target node
    int n = 30;

    std::vector<int> P;
    std::vector<int> Q;

    bool a = path(root, P, m);
    bool b = path(root, Q, n);

      if (a)
    {
        std::reverse(P.begin(), P.end());
        std::cout << "Path from root to " << m << ": ";
        for (int i = 0; i < P.size() ; i++)
        {
            std::cout << P[i] << " ";
        }
    }
       std::cout << " \n";


      if (b)
    {    
        std::reverse(Q.begin(), Q.end());
        std::cout << "Path from root to " << n << ": ";
        for (int i = 0; i < Q.size(); i++)
        {
            std::cout << Q[i] << " ";
        }
    }

   std::cout << " \n";

    int x = P.size();
    int y = Q.size();

    int i = -1;

    for (int j = 0; j < std::min(x,y); j++)
    {
        i++;
        if (P[j] != Q[j])
        {
            std::cout<< "First dist node: " <<  P[j] << std::endl;
            break;
        }
    }

    std::cout <<"First dist idx: " << i << std::endl;

    std::vector<int> fp;

    for (int j = x - 1; j >= i - 1; --j)
    {
        fp.push_back(P[j]);
    }

    for (int k = i; k <= y - 1; k++)
    {
        fp.push_back(Q[k]);
    }
     
     std::cout<< m << " to " << n << " : "; 
    for (int i = 0; i < fp.size(); i++)
    {
        std::cout << fp[i] << " ";
    }
     
    std::cout<< std::endl;

    std::reverse(fp.begin(), fp.end());

    std::cout<< n << " to " << m << " : ";
     for (int i = 0; i < fp.size(); i++)
    {
        std::cout << fp[i] << " ";
    }

    return 0;
}

