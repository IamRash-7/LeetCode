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
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int ins, int ine, int prs, int pre)
    {
        if(ins>ine || prs>pre)
            return NULL;
        
        TreeNode * node = new TreeNode(preorder[prs]);
        
        int pos;
        for(int i =ins; i<=ine; i++){
            if(inorder[i]==node->val)
                pos = i;
        }
        int len = pos-ins;
        
        node->left = createTree(preorder,inorder,ins,pos-1,prs+1,prs+len);
        node->right = createTree(preorder,inorder,pos+1,ine,prs+len+1,pre);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder,inorder,0,inorder.size()-1,0, preorder.size()-1);
    }
};