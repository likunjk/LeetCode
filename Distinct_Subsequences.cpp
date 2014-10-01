class Solution {
public:
    // 题目等价于：字符串S变换成字符串T有几种变法
    // 使用动态规划：dp[i][j]字符串S的前i个字符变换成T的前j个字符的方法数
    int numDistinct(string S, string T) 
    {
        int n = S.length();
        int m = T.length();
        if(n==0)
            return m==0;
        if(m==0)    //此时n!=0
            return 0;
        
        vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; ++i) //任何飞空串变换成空串只有1种方法
            dp[i][0] = 1;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                if(S[i-1]==T[j-1])  //因为字符串下标从0开始，所以要减1
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];   //相等时有2种选择：保留该字符或者舍弃该字符
                else
                    dp[i][j] = dp[i-1][j];  //不相等时，只能舍弃该字符
            }
        }
        return dp[n][m];
    }
};
