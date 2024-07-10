#include <iostream>
#include <stack>

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

 void inOrder(node *root){

    if(root == nullptr) return;

     std::stack<node *> st;
    node *curr = root;
    
    std::cout << "Inorder traversals: " ;

    while (!st.empty() || curr != nullptr)
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        std::cout << curr->data << " ";
        st.pop();
        curr = curr->right;
    }
 }

 void preOrder(node *root){
    if(root == nullptr) return ;
    
    std::stack<node*> st;
    st.push(root);
   
       std::cout << "\nPreorder traversals: " ;

    while(!st.empty()){
        node* temp = st.top();
        std::cout<< temp->data << " ";
        st.pop();

        if(temp->right != nullptr)  st.push(temp->right);
        if(temp->left != nullptr)  st.push(temp->left);
    }
 }

  void preOrder2(node *root){
    if(root == nullptr) return ;
    
    std::stack<node*> st;
    st.push(root);
     node* curr = root;

       std::cout << "\nPreorder traversals2: " ;
        while(!st.empty() || curr != nullptr){
            while(curr != nullptr){
                std::cout << curr->data << " ";
                st.push(curr->right);
                curr = curr->left;
            }
            if(st.size() > 0){
                curr = st.top();
                st.pop();
             //   curr = curr->right;
            }
        }
 }

 void postOrder(node *root){
    if(root == nullptr) return ;
    
    std::stack<node*> st;
    st.push(root);
   
       std::cout << "\npostOrder traversals: " ;
       node* curr = root;

    while(!st.empty()){

        if(curr->left != nullptr)  st.push(curr->left);
        if(curr->right != nullptr)  st.push(curr->right);

        node* temp = st.top();
        std::cout<< temp->data << " ";
        st.pop();
    }
 }

int main()
{
    node *root = insert(nullptr, 20);
    for (int value : {18, 15, 27, 12, 19, 10, 24, 30, 7, 1, 11, 29, 35, 5, 13, 33})
        insert(root, value);

    inOrder(root);
    std::cout<< std::endl;
    preOrder(root);
    std::cout<< std::endl;
    preOrder2(root);

    // postOrder(root); // try with using two stacks

    return 0;
}
