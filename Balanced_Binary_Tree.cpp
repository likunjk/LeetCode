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
    // 采取自底向上的方法，判断每个节点是否平衡
    int helper(TreeNode *root, bool &state)
    {
        if(root==NULL)  //NULL节点高度为-1
            return -1;
        
        int left = helper(root->left, state);
        int right = helper(root->right, state);
        
        if(abs(left-right) > 1)
            state = false;
        
        return max(left, right) + 1;    //返回单侧高度最高的那一个
    }
    
    bool isBalanced(TreeNode *root) 
    {
        bool state = true;
        
        helper(root, state);
        
        return state;
    }
};
