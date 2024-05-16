#include <iostream>
#include <vector>
#include <algorithm>
// given s node find count of all nodes which are k distance from s node

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


    int s = 15;
    int k = 3;

    std::vector<int> P;

     bool a = path(root, P, s);

    // std::reverse(P.begin(), P.end());
       
    if(a){
     for(int i = 0; i < P.size(); i++){
        std::cout << P[i] << " " ;
     }
}       

  // node *src = new node(15);

    count(P[(P.size()-1)], k);
    int ans = 0;
   k = k-1;
   for(int i = 1; i < P.size() && k > 0; i++){
    if(P[i]->left == P[i-1]){
        ans += count(P[i]->right, k-1);
    }
    else{
        ans += count(P[i]->left, k-1);
    }
    k = k-1;
   }

    return 0;
}