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
    // 关键：本题比较特殊，为满二叉树，可以实现O(1)空间的广搜
    // 下面的解法才是真正O(n)时间复杂度, O(1)空间复杂度的解法。递归的空间复杂度至少为log(n)
    void connect(TreeLinkNode *root) 
    {
        if(root==NULL)
            return ;
        while(root->left != NULL)
        {
            TreeLinkNode *p = root;
            while(p!=NULL)  //充分利用上一层节点的next信息
            {
                p->left->next = p->right;
                if(p->next!=NULL)
                    p->right->next = p->next->left;
                p = p->next;
            }
            root = root->left;
        }
    }
};
