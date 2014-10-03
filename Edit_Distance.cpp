class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n = word1.length();
        int m = word2.length();
        
        if(n==0)    //对特殊情况进行处理
            return m;
        if(m==0)
            return n;
        
        vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
        // dp[i][j]表示Word1的前i个字符和word2的前j个字符的最小编辑距离
        for(int i=0; i<=n; ++i)
            dp[i][0] = i;   //长度为i的字符串变为空串需要i次删除操作
        for(int j=0; j<=m; ++j)
            dp[0][j] = j;
            
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                if(word1[i-1] == word2[j-1])    //因为字符串的下标是从0开始的
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    // word1删除一个字符等价于word2插入一个字符
                    int tt = min(dp[i-1][j], dp[i][j-1]) + 1;   //删除或者插入一个字符
                    dp[i][j] = min(tt, 1+dp[i-1][j-1]); //替换一个字符
                }
            }
        }
        return dp[n][m];
    }
};
