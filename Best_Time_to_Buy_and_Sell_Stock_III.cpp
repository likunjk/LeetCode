class Solution {
public:
    // 这个题要特别注意：是说最多只能买卖2次，那么就有可能是0次、1次、2次
    // 一般说道2，就意味着可以进行二分，没错此题就是将其分成2部分，分别求每一部分能获得的最大利润
    int maxProfit(vector<int> &prices) 
    {
        int n = prices.size();
        if(n <= 1)
            return 0;
        int profit = 0;
        vector<int> dp(n, 0);
        dp[0] = 0;
        int leftMin = prices[0];
        for(int i=1; i<n; ++i)
        {
            dp[i] = max(dp[i-1], prices[i]-leftMin);
            leftMin = min(leftMin, prices[i]);
        }
        int rightProfit = 0;    //当从后往前扫描时，可以节省一个一维数组
        int rightMax = prices[n-1];
        for(int i=n-2; i>=0; --i)
        {
            rightProfit = max(rightProfit, rightMax-prices[i]);
            rightMax = max(rightMax, prices[i]);
            if(dp[i] + rightProfit > profit)    //最大值可能在[i,k]和[k,j]中取得，说明买卖一次就能取得最大收益，biru[1,2,3,4]
                profit = dp[i] + rightProfit;
        }
        return profit;
    }
};
