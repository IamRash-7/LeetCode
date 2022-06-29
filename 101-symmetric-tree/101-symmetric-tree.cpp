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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isequal(root->left,root->right);
    }
    bool isequal(TreeNode* l,TreeNode* r){
        if(l==NULL && r==NULL)
            return true;
        else if (!l || !r) {
            return false;
        }
        
        if(l->val != r->val)
            return false;
        bool b = isequal(l->left, r->right);
        bool c = isequal(l->right, r->left);
        if(c==false || b==false)
            return false;
        return true;
    }
};