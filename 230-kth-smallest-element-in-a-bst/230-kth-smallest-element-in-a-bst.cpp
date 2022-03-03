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
        vector<int> ans = recur(root,k,res);
        return ans[k-1];
    }
    
    vector<int> recur(TreeNode* root, int k, vector<int> res)
    {
        // go to the leftmost element
        if(root->left)
            res = recur(root->left,k,res);
        // push current element
        if(res.size()<k)
            res.push_back(root->val);
        // if right exists and 'k' elements have not yet been visited
        if(root->right && res.size()<k)
            res = recur(root->right,k,res);
        return res;
    }
};