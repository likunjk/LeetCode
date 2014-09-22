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
    // 返回每棵子树flatten之后的最后一个节点
    // 性质：每棵子树flatten之后的根节点还是自身
    TreeNode* helper(TreeNode *root)
    {
        if(root==NULL)
            return NULL;
           
        TreeNode *leftEnd = helper(root->left);
        TreeNode *rightEnd = helper(root->right);
        
        if(leftEnd != NULL) //当左边子树不为空时，需要先处理左子树
        {
            TreeNode *tp = root->right;
            root->right = root->left;
            root->left = NULL;
            leftEnd->right = tp;
            
            return rightEnd!=NULL ? rightEnd : leftEnd;
        }
        else
        {
            //左子树为空
            return rightEnd!=NULL ? rightEnd : root;
        }
    }
    void flatten(TreeNode *root) 
    {
        helper(root);
    }
};
