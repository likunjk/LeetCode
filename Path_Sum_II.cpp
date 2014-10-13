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
    //经典的深搜解决问题
    void helper(TreeNode *root, int k, int sum, vector<vector<int> > &ans, vector<int> &dp)
    {
        dp.push_back(root->val);
        k += root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(k==sum)
                ans.push_back(dp);
        }
        else
        {
            if(root->left!=NULL)
                helper(root->left, k, sum, ans, dp);
            if(root->right!=NULL)
                helper(root->right, k, sum, ans, dp);
        }
        dp.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) 
    {
        vector<vector<int> > ans;
        vector<int> dp;

        if(root==NULL)
            return ans;
        
        helper(root, 0, sum, ans, dp);
        return ans;
    }
};
