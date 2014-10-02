class Solution {
public:
    // O(n)复杂度，两个指针，一左一右，计算当前围城的面积。然后根据贪心原则，移动较小的那一个指针
    int maxArea(vector<int> &height) 
    {
        int ans = 0;
        for(int i=0, j=height.size()-1; i<j; )
        {
            int localMin = min(height[i], height[j]);
            int tt = localMin * (j-i);    //高度乘以宽度
            if(tt > ans)
                ans = tt;
            if(height[i] <= height[j])
                ++i;
            else
                --j;
        }
        return ans;
    }
};
