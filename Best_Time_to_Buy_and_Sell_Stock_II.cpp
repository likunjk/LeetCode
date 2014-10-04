class Solution {
public:
    // 既然是可以操作任意多次，那么每一次赚钱的机会都不能放过。
    int maxProfit(vector<int> &prices) 
    {
        int n = prices.size();
        if(n <= 1)
            return 0;
        
        int profit = 0;
        int small = prices[0];
        for(int i=0; i<n; ++i)
        {
            if(prices[i] <= small)
                small = prices[i];
            else if(prices[i] >= prices[i-1])   //当相邻几个点都是同值的波峰时，选择最后一个
            {
                // 若满足一下条件，则说明i点是峰点
                if( (i+1<n && prices[i] > prices[i+1]) || (i+1==n) )//这里需要注意边界条件
                {
                    profit += (prices[i]-small);
                    small = prices[i];
                }
            }
        }
        return profit;
    }
};
