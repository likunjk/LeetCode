int dp[1009][1009];

class Solution {
public:
    // 因为'*'与前面一个字符无关，不等同于正则匹配，为了不重复计算子问题，可以采用动态规划
    // 即使用动态规划，超大规模的案例仍然超时.不过跟普通方法相比，仍然快不少
    // 动态规划的复杂度是O(n*n*n), 考虑到每个点都是*，每个点都要循环n次判断
    bool isMatch(const char *s, const char *p) 
    {
        if(s==NULL || p==NULL)  //我们规定非法指针统一为false
            return false;
        
        memset(dp, -1, sizeof(dp));
        
        return helper(s, p, 0, 0);
    }
    
    bool helper(const char *s, const char *p, int i, int j)
    {
        if(dp[i][j]!=-1)    //返回计算过的子问题的解
            return dp[i][j];
            
        if(p[j]=='\0')
            return dp[i][j] = (s[i]=='\0');
        
        if(s[i]!='\0' && (s[i]==p[j] || p[j]=='?') )
            return dp[i][j] = helper(s, p, i+1, j+1);
        
        if(p[j]=='*')
        {
            if(helper(s, p, i, j+1)==true)
                return dp[i][j] = 1;
            int k = 1;
            while(s[i+k-1]!='\0')
            {
                if(helper(s, p, i+k, j+1)==true)
                    return dp[i][j] = 1;
                ++k;
            }
            return dp[i][j] = 0;
        }
        return dp[i][j] = 0;
    }
};
