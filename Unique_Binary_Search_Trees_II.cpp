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
    // 比前一题有明显难度，动态规划的方法是行不通了。必须采用递归
    vector<TreeNode *> generateTrees(int n) 
    {
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int left, int right)   //不能为了速度返回引用，因为是局部变量
    {
        vector<TreeNode*> ans;
        
        if(left > right)    //边界条件，即使不满足，也要返回NULL
        {
            ans.push_back(NULL);
            return ans;
        }
        
        for(int i=left; i<=right; ++i)  //枚举根节点
        {
            vector<TreeNode*> leftAns = helper(left, i-1);  //因为是二叉搜索树，所以必须保证左边的元素小于根，右边的元素大于根
            vector<TreeNode*> rightAns = helper(i+1, right);
            
            for(int j=0; j<leftAns.size(); ++j)
            {
                for(int k=0; k<rightAns.size(); ++k)
                {
                    TreeNode *root = new TreeNode(i);   //root每次都要生成，不然会改变前面的结果
                    root->left = leftAns[j];    //将左右子树的结果两两组合
                    root->right = rightAns[k];
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
};
