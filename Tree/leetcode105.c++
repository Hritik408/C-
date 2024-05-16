/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         return construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    private:
    TreeNode* construct(vector<int>& preOrder, int ps, int pe, vector<int>& inOrder, int ins, int ine){
        if(ps > pe) return nullptr;
        TreeNode* root = new TreeNode(preOrder[ps]);
        int idx = -1;
        size_t index = 0;

        for(int item : inOrder){
            if(item == preOrder[ps]){
                idx = index;
                break;
            }
            index++;
        }

        int x = idx - ins;

        root->left = construct(preOrder, ps+1, ps+x, inOrder, ins, idx-1);
        root->right = construct(preOrder, ps+x+1, pe, inOrder, idx+1, ine);

        return root;
    }
};