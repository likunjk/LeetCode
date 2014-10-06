class Solution {
public:
    // 如果直接在原数组上面操作，可以只采用常数空间
    int minimumTotal(vector<vector<int> > &triangle) 
    {
        int n = triangle.size();    //在面试的时候还要问清楚，如果给空vector怎么办?
        
        for(int i=n-2; i>=0; --i)   //采用从底往上的思路，就不用最后扫描最小值
        {
            for(int j=0; j<=i; ++j)
            {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        
        return triangle[0][0];
    }
};
