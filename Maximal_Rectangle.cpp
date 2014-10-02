class Solution {
public:
    // 这个题有两个关键点：
    // 1: O(n)的时间复杂度确定每一行每个位置上1的高度，形成1个高度矩阵
    // 2: O(n)的时间复杂度在上面找出的高度矩阵中找出最大矩阵
    int maximalRectangle(vector<vector<char> > &matrix) 
    {
        int n = matrix.size();
        if(n==0)
            return 0;
        int m = matrix[0].size();
        if(m==0)
            return 0;
        //正式处理
        vector<int> dp(m+1, 0);
        dp[m] = -1; //多添加一个-1，方便处理
        int ans = 0;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(matrix[i][j]=='0')
                    dp[j] = 0;
                else
                    dp[j] = dp[j]+1;
            }
            int tt = helper(dp);
            if(tt > ans)
                ans = tt;
        }
        return ans;
    }
    
    int helper(vector<int> &dp)
    {
        int ans = 0;
        stack<int> st;
        for(int i=0; i<dp.size(); )
        {
            if(!st.empty() && dp[i] < dp[st.top()])
            {
                int tt = st.top();
                st.pop();
                
                int local = 0;
                if(st.empty())
                    local = dp[tt]*i;
                else
                    local = dp[tt]*(i-st.top()-1);
                if(local > ans)
                    ans = local;
            }
            else
            {
                st.push(i++);
            }
        }
        return ans;
    }
};
