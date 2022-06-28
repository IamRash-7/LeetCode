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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            while(size-->0)
            {
                TreeNode* fr = q.front();
                q.pop();
                temp.push_back(fr->val);
                
                if(fr->left)
                    q.push(fr->left);
                if(fr->right)
                    q.push(fr->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};