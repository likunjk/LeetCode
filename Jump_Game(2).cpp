class Solution {
public:
    // 第一题只是问能不能到达，其实可以采取更简单的做法。时间复杂度O(n)
    bool canJump(int A[], int n) 
    {
        if(n==0)
            return true;
        int maxStep = A[0]; //maxStep表示当前能到达最远位置
        for(int i=1; i<n; ++i)
        {
            if(maxStep > 0)
            {
                maxStep--;  //为了走到当前位置，先减1
                maxStep = max(maxStep, A[i]);   //贪心策略
            }
            else
            {
                // 说明当前位置不能到达
                return false;
            }
        }
        return true;
    }
};
