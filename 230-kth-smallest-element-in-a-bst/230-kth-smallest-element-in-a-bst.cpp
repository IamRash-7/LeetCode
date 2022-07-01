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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        recur(root,res,k);
        return res[k-1];
    }
    
    void recur(TreeNode* root, vector<int>& res, int k)
    {
        if(root==NULL)
            return;
        if(res.size()>k)
            return;
        
        recur(root->left,res,k);
        res.push_back(root->val);
        recur(root->right,res,k);
    }
};