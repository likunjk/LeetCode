class Solution {
public:
    // 经典题目，利用一个变量保存左边的最小值，然后求每个位置能获取的最大利润
    int maxProfit(vector<int> &prices) 
    {
        if(prices.size()==0)
            return 0;

        int profit = 0;
        int leftMin = prices[0];
        for(int i=1; i<prices.size(); ++i)
        {
            if(prices[i]-leftMin > profit)
                profit = prices[i]-leftMin;
            if(prices[i] < leftMin)
                leftMin = prices[i];
        }
        
        return profit;
    }
};
