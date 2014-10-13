/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode *root, int deep, int &ans)
    {
        if(root->left==NULL && root->right==NULL)
        {
            if(deep < ans)
                ans = deep;
        }
        if(root->left)
            helper(root->left, deep+1, ans);
        if(root->right)
            helper(root->right, deep+1, ans);
    }
    int minDepth(TreeNode *root) 
    {
        if(root==NULL)
            return 0;
        
        int ans = 0x7fffffff;
        helper(root, 1, ans);   //根节点深度为1
        
        return ans;
    }
};
