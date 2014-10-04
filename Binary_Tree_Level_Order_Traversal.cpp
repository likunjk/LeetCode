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
    vector<vector<int> > levelOrder(TreeNode *root) 
    {
        vector<vector<int> > ans;
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);   //初始化
        q.push(NULL);
        vector<int> tmp;
        while(!q.empty())
        {
            TreeNode *p = q.front();
            q.pop();
            if(p!=NULL)
            {
                tmp.push_back(p->val);
                if(p->left!=NULL)
                    q.push(p->left);
                if(p->right!=NULL)
                    q.push(p->right);
            }
            else    //说明当前层结束，如果后面还有元素，就需要给下一层添加一个结尾标记
            {
                ans.push_back(tmp);
                tmp.clear();
                if(!q.empty())      
                    q.push(NULL);
            }
        }
        return ans;
    }
};
