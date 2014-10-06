class Solution {
public:
    // 经典的动态规划题目：dp[i] = dp[i-1]+dp[i-2]，也就是斐波拉切数列
    // 如果数据量小的话，可以直接循环，如果很大的话可以采用二分、矩阵乘法
    int climbStairs(int n) 
    {
        vector<int> dp(n+1, 1); //dp[0] = dp[1] = 1
        for(int i=2; i<=n; ++i)
            dp[i] = dp[i-1]+dp[i-2];
            
        return dp[n];
    }
};
