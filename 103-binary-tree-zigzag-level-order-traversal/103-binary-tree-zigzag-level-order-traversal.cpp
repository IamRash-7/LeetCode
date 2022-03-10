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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL)
            return ans;
        int val = 0;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> res(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if(val == 0)
                    res[i] = tmp->val;
                else
                    res[n-1-i] = tmp->val;
                
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            ans.push_back(res);
            val = !val;
        }
        return ans;
    }
};