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
    // 刚开始拿到这道题目时有几个疑问，究竟要怎样才能找出被错误交换的节点？
    // 比如{2,1,3}和{2,3,1}，前面一棵二叉树被交换的节点相邻，后面一棵二叉树被交换的节点不相邻。
    // 后来想起O(n)空间复杂度的方法，先中序遍历一遍二叉树，然后进行检查。
    // 上面两颗二叉树中序遍历的结果分别是{2,1,3}和{3,2,1}. 我们可以发现如果是相邻的节点被交换，
    // 那么在中序遍历的结果中只有一个位置不合法(2,1)；如果被交换的节点不相邻，那么就有2个位置不合法(3,2)(2,1)
    // 因此我们就可以对二叉树进行中序遍历，记录不合法的次数，及相应的位置
    
    TreeNode *pre;  
    TreeNode *p1, *p2;
    void recoverTree(TreeNode *root) 
    {
        pre = NULL; //记录当前节点的中序遍历的前一个节点
        p1 = p2 = NULL; //记录出现错误的位置
        
        helper(root);
        
        if(p1!=NULL && p2!=NULL)    //进行交换前最好判断，万一root为NULL呢
        {
            int tt = p1->val;   //此处的
            p1->val = p2->val;
            p2->val = tt;
        }
    }
    
    void helper(TreeNode *root)
    {
        if(root==NULL)
            return ;
        
        helper(root->left);
        
        if(pre!=NULL && pre->val > root->val)
        {
            if(p1==NULL)    //说明是第一次发现错误
            {
                p1 = pre;
                p2 = root;
            }
            else    //说明是第二次发现错误
            {
                p2 = root;  //p1已经用于记录另外一个节点, 想一下例子{2,3,1}的中序遍历{3,2,1}
            }
        }
        pre = root; //这句不要给忘了啊!!!
        
        helper(root->right);
    }
};
