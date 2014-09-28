class Solution {
public:
    // 前天刚做过的题目，应该是小米的笔试题
    int maxProduct(int A[], int n) 
    {
        if(n <= 0)
            return 0;
        
        int localMax = A[0];
        int localMin = A[0];
        int ans = A[0];
        for(int i=1; i<n; ++i)
        {
            int t1 = max(A[i], max(A[i]*localMax, A[i]*localMin) );
            int t2 = min(A[i], min(A[i]*localMax, A[i]*localMin) );
            
            localMax = t1;
            localMin = t2;
            
            if(localMax > ans)
                ans = localMax;
        }
        
        return ans;
    }
};
