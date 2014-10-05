class Solution {
public:
    // 原则：无论何时，左括号数要大于等于右括号
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        if(n <= 0)
            return ans;
        
        vector<char> tmp;
        helper(ans, tmp, 0, 0, n);
        
        return ans;
    }
    void helper(vector<string> &ans, vector<char> &tmp, int left, int right, int n)
    {
        if(left > n || right > n)
            return ;
        
        if(left==n && right==n)
        {
            ans.push_back(string(tmp.begin(), tmp.end()));
            return;
        }
        if(left==right) //当左括号等于右括号时只能放左括号
        {
            tmp.push_back('(');
            helper(ans, tmp, left+1, right, n);
            tmp.pop_back();
        }
        else
        {
            tmp.push_back('(');
            helper(ans, tmp, left+1, right, n);
            tmp.pop_back();
            
            tmp.push_back(')');
            helper(ans, tmp, left, right+1, n);
            tmp.pop_back();            
        }
    }
};
