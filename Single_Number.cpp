class Solution {
public:
    // 最简单的一种情况，详见：http://www.likunjk.com/article/1398955756.html
    int singleNumber(int A[], int n) 
    {
        int ans = 0;
        for(int i=0; i<n; ++i)
            ans ^= A[i];
        return ans;
    }
};
