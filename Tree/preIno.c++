#include <iostream>

struct node{
    int data;
    node *left;
    node *right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

node* insert(node *root, int value){
    if(root == nullptr)  return new node(value);

    if(rand() % 2 == 0)
     root->left = insert(root->left, value);
    else    
    root->right = insert(root->right, value);

    return root;
}

node* construct(int pre[], int ps, int pe, int in[], int ins, int ine){

    if(ps > pe) return nullptr;
    node* root = new node(pre[ps]);  // allocate memory for a new node
    int ind = -1;

    for(int i = ins; i <= ine; i++){
        if(pre[ps] == in[i]){
        ind = i;
        break;
        }
    }

    int x = ind - ins;

    root->left = construct(pre, ps+1, ps+x, in, ins, ind-1);
    root->right = construct(pre, ps+x+1, pe, in, ind+1, ine);

    return root;

}

void postorder(node* root){
    if(root == nullptr) return ;

     if(root != nullptr)
     {
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
     }

}

int main(){
    node* root = insert(nullptr, 20);
    for(int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
    insert(root, value);

    int pre[] = {20, 27, 19, 10, 1, 11, 18, 15, 12, 29, 7, 35, 5, 13, 24, 33, 30};
    int in[] = {19, 27, 11, 1, 10, 20, 12, 29, 15, 35, 7, 13, 5, 18, 33, 24, 30};

    int n = 17;

  node* ans =  construct(pre, 0, n-1, in, 0, n-1);

  postorder(ans);

    return 0;
}