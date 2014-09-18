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
    //经典的递归题目，上次搜狐校招的面试题目
    bool isSameTree(TreeNode *p, TreeNode *q) 
    {
        if(p==NULL)
            return q==NULL;
        if(q==NULL)
            return p==NULL;
            
        if(p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
};
