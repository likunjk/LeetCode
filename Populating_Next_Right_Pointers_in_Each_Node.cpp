/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    // 关键：充分利用父亲节点的next信息
    void connect(TreeLinkNode *root) 
    {
        if(root==NULL)
            return ;
        if(root->left!=NULL)    //因为题目保证是满二叉树，所以可以这样处理
        {
            root->left->next = root->right;
        }
        if(root->right!=NULL)
        {
            if(root->next!=NULL)
                root->right->next = root->next->left;
        }
        connect(root->right);
        connect(root->left);
    }
};
