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
    int helper(TreeNode *root, int &ans)
    {
        if(root==NULL)
            return 0;
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        
        int tt = left + right + root->val;
        if(tt > ans)
            ans = tt;
        return max(0, max(left, right)+root->val);
    }
    //此题需要问清楚，如全部节点为负数，是返回最大的负数，还是0
    int maxPathSum(TreeNode *root) 
    {
        if(root==NULL) 
            return 0;
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};
