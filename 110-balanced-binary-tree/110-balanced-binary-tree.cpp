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
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        
//         int hl = height(root->left);
//         int hr = height(root->right);
        
//         if(!isBalanced(root->left))
//             return false;
//         if(!isBalanced(root->right))
//             return false;
        
//         if(abs(hl-hr)>1)
//             return false;
        int maxi = 0;
        height(root,maxi);
        if(maxi>1)
            return false;
        
        return true;
    }
    
    int height(TreeNode* root, int &maxi)
    {
        if(root==NULL)
            return 0;
        
        int ll = height(root->left,maxi);
        int rr = height(root->right,maxi);
        
        maxi = max(maxi,abs(ll-rr));
        
        return max(ll,rr)+1;
    }
};