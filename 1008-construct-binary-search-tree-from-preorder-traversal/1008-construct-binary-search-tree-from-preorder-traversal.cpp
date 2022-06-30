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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return recur(preorder,0,preorder.size()-1);
    }
    
    TreeNode* recur(vector<int>& preorder, int start, int end)
    {
        if(start>end || start<0 || end>=preorder.size())
            return NULL;
        
        int value = preorder[start];
        TreeNode* root = new TreeNode(value); 
        int i;
        for(i=start;i<=end;i++)
        {
            if(preorder[i]>value)
                break;
        }
        root->left = recur(preorder,start+1,i-1);
        root->right = recur(preorder,i,end);
        return root;
    }
};