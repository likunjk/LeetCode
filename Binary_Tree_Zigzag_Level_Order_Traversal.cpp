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
    // 简单的层次遍历，采用队列实现，每层结尾插入NULL区分
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
    {
        vector<vector<int> > ans;
        if(root==NULL)
            return ans;
        
        vector<int> dp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool state = true;  //true-正向   false-反向
        while(!q.empty())
        {
            TreeNode *p = q.front();
            q.pop();
            if(NULL != p)
            {
                dp.push_back(p->val);
                if(p->left!=NULL)
                    q.push(p->left);
                if(p->right!=NULL)
                    q.push(p->right);
            }
            else
            {
                if(state==false)
                    reverse(dp.begin(), dp.end());
                state = !state;
                ans.push_back(dp);
                dp.clear();
                if(!q.empty())  //说明还有元素，则给下一层加入末尾标记NULL
                    q.push(NULL);
            }
        }
        
        return ans;
    }
};
