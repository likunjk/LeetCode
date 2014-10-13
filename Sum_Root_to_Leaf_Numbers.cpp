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
    //典型的深搜题目
    void helper(TreeNode *root, int &ans, vector<int> &tmp)
    {
        tmp.push_back(root->val);   //压入
        if(root->left==NULL && root->right==NULL)
        {
            int tt = 0;
            for(int i=0; i<tmp.size(); ++i)
                tt = tt*10 + tmp[i];
            ans += tt;
        }
        else
        {
            if(root->left!=NULL)
                helper(root->left, ans, tmp);
            if(root->right!=NULL)
                helper(root->right, ans, tmp);
        }
        tmp.pop_back(); //弹出
    }
    int sumNumbers(TreeNode *root) 
    {
        if(root==NULL)
            return 0;
        
        int ans = 0;
        vector<int> tmp;
        helper(root, ans, tmp);
        
        return ans;
    }
};
