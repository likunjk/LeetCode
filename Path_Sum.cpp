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
    void helper(TreeNode *root, int k, int sum, bool &ans)
    {
        k += root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(k==sum)
                ans = true;
        }
        else
        {
            if(root->left!=NULL)
                helper(root->left, k, sum, ans);
            if(root->right!=NULL)
                helper(root->right, k, sum, ans);
        }
    }
    bool hasPathSum(TreeNode *root, int sum) 
    {
        if(root==NULL)  //这里要问下面试官，如果sum==0,并且root==NULL时该返回什么
            return false;
        
        bool ans = false;
        helper(root, 0, sum, ans);
        
        return ans;
    }
};
