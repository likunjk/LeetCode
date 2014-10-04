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
    // 从严格意义上来说：递归也是有空间复杂度的
    // 下面采用真正的O(1)空间复杂度+O(n)的时间复杂度解题
    void connect(TreeLinkNode *root) 
    {
        if(root==NULL)
            return ;
        while(root!=NULL)   //root表示当前层的第一个不为NULL的节点
        {
            //寻找下一层第一个不为NULL的节点
            TreeLinkNode *p = root;
            TreeLinkNode *first = NULL;
            while(p!=NULL)
            {
                if(p->left!=NULL)
                {
                    first = p->left;
                    break;
                }
                if(p->right!=NULL)
                {
                    first = p->right;
                    break;
                }
                p = p->next;
            }
            if(first==NULL) //说明下一层全部为NULL节点
                break;
            
            root = first;   //保存下一层的起始节点，为下下一层做准备
            
            //为了方便处理, 对同时存在左右字节点的情况进行特殊处理
            if(first==p->left && p->right!=NULL)
            {
                first->next = p->right;
                first = p->right;
            }
            p = p->next;    //充分利用当前层的信息，对下面一层进行处理
            while(p!=NULL)
            {
                if(p->left!=NULL)
                {
                    first->next = p->left;
                    first = p->left;
                }
                if(p->right!=NULL)
                {
                    first->next = p->right;
                    first = p->right;
                }
                p = p->next;
            }
        }
    }
};
