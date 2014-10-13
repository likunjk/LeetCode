class Solution {
public:
    int candy(vector<int> &ratings) 
    {
        int n = ratings.size();
        if(n <= 1)
            return n;
        
        vector<int> dp(n, 1);   //每个小孩至少有1个糖果
        for(int i=1; i<n; ++i)
        {
            if(ratings[i] > ratings[i-1])   //先满足若右边孩子排名比左边高，则其获得的糖果数+1
                dp[i] = dp[i-1]+1;
        }
        int ans = dp[n-1];
        for(int i=n-2; i>=0; --i)
        {
            if(ratings[i] > ratings[i+1])   //在满足上面的基础上，再满足右边的条件
                dp[i] = max(dp[i], dp[i+1]+1);
            ans += dp[i];
        }
        // 经过2遍扫描，可以确保左右条件都满足，并且总共需要的糖果数最小
        return ans;
    }
};
