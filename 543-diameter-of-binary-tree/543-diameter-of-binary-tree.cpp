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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int hl = height(root->left);
        int hr = height(root->right);
        
        int dial = diameterOfBinaryTree(root->left);
        int diar = diameterOfBinaryTree(root->right);
        
        return max(dial,max(diar,hl+hr));
        
    }
    
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int dl = height(root->left);
        int dr = height(root->right);
        
        return max(dl,dr)+1;
    }
};