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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int size = q.size();
            int mini = q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
            {
                int cur = q.front().second - mini;
                TreeNode* tmp = q.front().first;
                q.pop();
                
                if(i==0)
                    first = cur;
                if(i==size-1)
                    last = cur;
                
                if(tmp->left)
                    q.push({tmp->left,2LL*cur+1});
                if(tmp->right)
                    q.push({tmp->right,2LL*cur+2});
            }
           ans = max(ans,last-first+1); 
        }
        return ans;
    }
};