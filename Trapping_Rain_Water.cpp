class Solution {
public:
    // 思路：确定每个位置能装多少水，方法是找出每个位置左右的最大值
    int trap(int A[], int n) 
    {
        if(n==0)
            return 0;
        vector<int> dp(n);
        dp[0] = 0;
        for(int i=1; i<n; ++i)
            dp[i] = max(dp[i-1], A[i-1]);
        int rightMax = 0;
        int ans = 0;
        for(int i=n-2; i>=0; --i)
        {
            rightMax = max(rightMax, A[i+1]);
            int localMin = min(dp[i], rightMax);    //取左右最大值的较小者
            if(localMin > A[i])
                ans += (localMin-A[i]);
        }
        return ans;
    }
};
