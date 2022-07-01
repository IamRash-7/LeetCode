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
class prop{
  public:
    int minval, maxval, maxsum;
    bool isbst;
    prop(){
        isbst=true;
        minval = INT_MAX;
        maxval = INT_MIN;
        maxsum = 0;
    }
};


class Solution {
    int ans = 0;
public:
    prop calsum(TreeNode* root)
    {
        if(root==NULL)
            return prop();
        
        prop p;
        prop l = calsum(root->left);
        prop r = calsum(root->right);
        
        if(l.isbst && r.isbst && l.maxval < root->val && r.minval > root->val)
        {
            p.isbst = true;
            p.maxsum = l.maxsum + r.maxsum + root->val;
            p.minval = min(l.minval,root->val);
            p.maxval = max(r.maxval,root->val);
        }
        else
        {
            p.isbst = false;
            p.maxsum = max(l.maxsum, r.maxsum);
        }
        
        ans=max(ans, p.maxsum);
        return p;
    }
    
    int maxSumBST(TreeNode* root) {
        calsum(root);
        return ans;
    }
};