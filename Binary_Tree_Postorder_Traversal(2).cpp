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
    // 新方法：采用根、右、左的顺序进行遍历，然后将结果进行反转，就是我们期望的后续遍历结果
    // 好处在于可以使用前序遍历的方式，不用再自定义节点，保存每个节点的访问次数
    vector<int> postorderTraversal(TreeNode *root) 
    {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *p = root;
        
        while(p!=NULL || !st.empty())
        {
            while(p!=NULL)
            {
                ans.push_back(p->val);
                st.push(p);
                p = p->right;   //这里是一直往右子树遍历
            }
            if(!st.empty())
            {
                p = st.top();
                st.pop();
                p = p->left;
            }
        }
        
        reverse(ans.begin(), ans.end());    //反转
        
        return ans;
    }
};
