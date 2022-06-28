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
        if(root==NULL || root->val == q->val || root->val==p->val)
            return root;
        
        TreeNode* p_left = lowestCommonAncestor(root->left,p,q);
        TreeNode* q_right = lowestCommonAncestor(root->right,p,q);
        
        if(p_left!=NULL && q_right!=NULL)
            return root;
        
        if(p_left!=NULL && q_right==NULL)
            return p_left;
        else
            return q_right;
    }
    
//     bool find(TreeNode* root, TreeNode* target)
//     {
//         if(root==NULL)
//             return false;
//         if(root->val == target->val)
//             return true;
        
//         if(find(root->left, target))
//             return true;
//         if(find(root->right,target))
//             return true;
        
//         return false;
//     }
};