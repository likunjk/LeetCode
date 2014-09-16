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
    struct Node
    {
        TreeNode *root;
        bool flag;  //标记一个节点是否前面已经从堆栈中弹出过
        Node(TreeNode *p, bool f) : root(p), flag(f){}
    };
    
    // 因为后续遍历当一个节点从堆栈弹出时，还不一定立即访问，因为可能这次是进行右孩子的遍历
    vector<int> postorderTraversal(TreeNode *root) 
    {
        stack<Node> st;
        vector<int> ans;
        
        TreeNode *p = root;
        
        while(p != NULL || !st.empty())
        {
            while(p != NULL)
            {
                st.push(Node(p, false));
                p = p->left;
            }
            if(!st.empty())
            {
                Node tt = st.top();
                st.pop();
                if(tt.flag == true)   //说明是第二次弹出，右孩子已经访问完毕
                {
                    ans.push_back(tt.root->val);
                }
                else    //说明是第一次弹出，那么需要再次入栈，然后访问右孩子
                {
                    st.push(Node(tt.root, true));
                    p = tt.root->right;
                }
            }
        }
        
        return ans;
    }
};
