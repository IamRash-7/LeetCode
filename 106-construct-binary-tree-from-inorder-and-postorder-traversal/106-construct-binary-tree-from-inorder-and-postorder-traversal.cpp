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
    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder,int is,int ie,int ps,int pe){
        if(ps > pe){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[pe]);
        
        int pos;
        for(int i =is; i<=ie; i++){
            if(inorder[i]==root->val)
                pos = i;
        }
        
        int len = pos-is;
        
        root->left = createTree(inorder,postorder,is, pos-1, ps, ps + len - 1);
        root->right = createTree(inorder, postorder, pos+1, ie,  ps + len, pe - 1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createTree(inorder, postorder, 0,inorder.size()-1, 0, postorder.size()-1);
    }
};