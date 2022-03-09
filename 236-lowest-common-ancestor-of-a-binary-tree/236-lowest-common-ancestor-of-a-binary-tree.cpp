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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        return recur(root, p, q);
    }
    
    TreeNode* recur(TreeNode* root, TreeNode *p, TreeNode *q)
    {

        if(root == NULL || root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* pl = recur(root->left, p,q);
        TreeNode* ql = recur(root->right,p,q);
        if(pl != NULL && ql != NULL)
            return root;
        if (pl != NULL) return pl;
        return ql;
    }
};