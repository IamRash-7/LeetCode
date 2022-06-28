/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val)
            return root;
        if(root->val == q->val)
            return root;
        bool p_left = find(root->left,p);
        bool q_right = find(root->right,q);
        
        if(p_left && q_right)
            return root;
        else if(p_left==true && q_right==false)
            return lowestCommonAncestor(root->left,p,q);
        else if(p_left==false && q_right==true)
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
    
    bool find(TreeNode* root, TreeNode* target)
    {
        if(root==NULL)
            return false;
        if(root->val == target->val)
            return true;
        
        if(find(root->left, target))
            return true;
        if(find(root->right,target))
            return true;
        
        return false;
    }
};