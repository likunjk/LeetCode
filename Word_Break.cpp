class Solution {
public:
    int helper(unordered_set<string> &dict, vector<int> &dp, string &s, int index)
    {
        if(dp[index]!=-1)   //-1表示状态还未确定
            return dp[index];
        
        int n = s.length();
        
        if(dict.find(s.substr(index, n-index))!=dict.end()) //说明整个串就是一个合法单词
            return dp[index] = 1;
        
        
        for(int i=index; i<n-1; ++i)    //这里要注意不能取整个串，因为前面已经处理过了
        {
            if(dict.find(s.substr(index, i-index+1))!=dict.end())
            {
                if(helper(dict, dp, s, i+1)==1) //一旦有满足要求的，直接返回
                    return dp[index] = 1;
            }
        }
        return dp[index] = 0;   //说明从当前位置开始不能成功分裂
    }
    bool wordBreak(string s, unordered_set<string> &dict) 
    {
        int n = s.length();
        if(n==0)
            return false;
        
        vector<int> dp(n, -1);  //dp[i]表示从位置i开始到末尾的字符串能否成功分裂
        helper(dict, dp, s, 0);
        
        return dp[0];
    }
};
