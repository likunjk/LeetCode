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
    //二叉树的前序遍历，非递归
    vector<int> preorderTraversal(TreeNode *root) 
    {
        stack<TreeNode*> st;
        vector<int> ans;
        
        TreeNode *p = root; //p是左孩子指针
        while(p!=NULL || !st.empty())   //必须是这两个条件都不满足时才退出   
        {
            while(p!=NULL)  //当左孩子不为空时，继续往左深入
            {
                ans.push_back(p->val);
                st.push(p);    // 确保压入堆栈的节点都不为空
                p = p->left;
            }
            if(!st.empty()) //运行到这里，说明此时左孩子为空，于是进行回溯
            {
                p = st.top();   //弹出根节点，指向右孩子节点
                st.pop();
                p = p->right;   //此时右孩子节点也可能为空，但是不用担心，当堆栈不为空时，程序会再次运行到这里
            }
        }
        
        return ans;
    }
};
