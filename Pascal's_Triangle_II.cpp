class Solution {
public:
    // 使用两个vector可以很方便的解决问题，但是有点浪费
    // 其实只要策略好，一个vector也是可以的
    vector<int> getRow(int rowIndex) 
    {
        vector<int> ans(rowIndex, 0);
        ans.push_back(1);
        
        if(rowIndex==0)
            return ans;
        
        for(int i=1; i<=rowIndex; ++i)
        {
            ans[i] = 1;
            //从后往前处理，就不会破坏原信息了。很多算法的优化都是这种策略。比如0-1背包
            for(int j=i-1; j>=1; --j)
                ans[j] = ans[j-1]+ans[j];
            ans[0] = 1;
        }
        
        return ans;
    }
};
