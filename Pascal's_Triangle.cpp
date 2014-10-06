class Solution {
public:
    // 典型的动态规划题目
    vector<vector<int> > generate(int numRows) 
    {
        vector<vector<int> > error;
        if(numRows <= 0)
            return error;
        
        vector<vector<int> > ans(numRows);  //此处若numRows==0,是会出错的
        
        ans[0].push_back(1);    //对第一行特殊处理
        
        for(int i=1; i<numRows; ++i)
        {
            ans[i].push_back(1);
            for(int j=1; j<i; ++j)
                ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
            ans[i].push_back(1);
        }
        
        return ans;
    }
};
