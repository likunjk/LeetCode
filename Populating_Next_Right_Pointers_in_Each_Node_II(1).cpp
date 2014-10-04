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
    // 老实说来：采用递归也是不符合要求的，因为递归需要栈空间，空间复杂度为log(n)
    void connect(TreeLinkNode *root) 
    {
        if(root==NULL)
            return ;
        // 对一个节点来说，先处理左孩子还是右孩子没有关系
        if(root->left!=NULL)
        {
            if(root->right!=NULL)
            {
                root->left->next = root->right;
            }
            else
            {
                TreeLinkNode *p = root->next;   //两个while循环只可能执行一个
                while(p!=NULL)
                {
                    if(p->left!=NULL)
                    {
                        root->left->next = p->left;
                        break;
                    }
                    if(p->right!=NULL)
                    {
                        root->left->next = p->right;
                        break;
                    }
                    p = p->next;
                }
            }
        }
        if(root->right!=NULL)
        {
            TreeLinkNode *p = root->next;
            while(p!=NULL)
            {
                if(p->left!=NULL)
                {
                    root->right->next = p->left;
                    break;
                }
                if(p->right!=NULL)
                {
                    root->right->next = p->right;
                    break;
                }
                p = p->next;
            }
        }
        connect(root->right); //这里一定要注意顺序，先处理右子树，再处理左子树
        connect(root->left);
    }
};
