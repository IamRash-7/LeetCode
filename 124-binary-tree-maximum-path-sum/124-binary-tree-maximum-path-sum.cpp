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
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        recur(root,sum);
        return sum;
    }
    
    int recur(TreeNode*root, int &sum)
    {
        if(root==NULL)
            return 0;
        int left,right;
        left = max(0,recur(root->left,sum));
        right = max(0,recur(root->right,sum));
        
        sum = max(sum,(left+right+root->val));
        
        return root->val+max(right,left);
    }
};