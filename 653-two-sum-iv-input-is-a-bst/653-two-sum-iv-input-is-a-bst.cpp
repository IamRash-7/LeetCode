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
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        findin(root,res);
        
        int i = 0;
        int j = res.size()-1;
        while(i<j)
        {
            int sum = res[i]+res[j];
            if(sum==k)
                return true;
            else if(sum>k)
                j--;
            else
                i++;
        }
        return false;
    }
    
    void findin(TreeNode* root, vector<int>& res)
    {
        if(root==NULL)
            return;
        
        findin(root->left, res);
        res.push_back(root->val);
        findin(root->right,res);
    }
};