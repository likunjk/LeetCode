class Solution {
public:
    // 动态规划解题。dp[i]表示从起始位置跳转到i位子的最少步数
    // dp[i] = min(dp[i-k])+1 (1<= k <=i && A[i-k]>=k) 枚举前面i-k位置到达i的最小步数
    int jump(int A[], int n) 
    {
        if(n==0)
            return 0;
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;  //初始化
        for(int i=1; i<n; ++i)
        {
            for(int k=i; k>=1; --k) //普通的二重循环是会超时的，必须要加以优化
            {
                // 这里子所以判断dp[i-k]!=INT_MAX，是因为INT_MAX+1会溢出，若不想判断，就将初始值舍小一点
                if(A[i-k] >= k && dp[i-k]!=INT_MAX && dp[i] > dp[i-k]+1)    //必须保证i-k位置能1步到达i位置,并且i-k能够到达
                {
                    dp[i] = dp[i-k]+1;
                    break;  //如果我能通过前面某个点p到达，那么就不用再计算后面的点q(q>p)了。因为你后面的点也是需要我前面的点到的吧
                }
            }
        }
        return dp[n-1]; //若最后dp[n-1]==INT_MAX, 则说明该点无法到达   
    }
};
