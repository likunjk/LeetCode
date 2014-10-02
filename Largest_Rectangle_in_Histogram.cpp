class Solution {
public:
    // 核心思路：计算以每个点的高度为基准形成的最大面积，也就是说在形成的矩形中，其他所有点的高度都要大于等于当前点。
    // 因为维护的是一个递增栈，并且右边的元素（准备进栈）的值要小于当前值，所以只需要考虑左边的即可
    // 下面这张图片解释的很清楚：http://images.cnitblog.com/blog/466943/201307/18095649-645e12c5653440f2a9e2ca7b505a3082.png
    int largestRectangleArea(vector<int> &height) 
    {
        vector<int> dp(height); //为了不破坏原数组，拷贝一份
        dp.push_back(-1);  //在尾部增加一个-1是为了方便后续的处理
        int n = dp.size();
        
        stack<int> st;
        int ans = 0;
        for(int i=0; i<n; )
        {
            //只有当前值比栈顶元素小才需要处理，其余通通入栈。也就是说我们的栈是一个连续的递增的栈
            if(!st.empty() && dp[i] < dp[st.top()]) 
            {
                int tt = st.top();
                st.pop();
                
                int local = 0;
                if(st.empty()) //说明当前元素是整个堆栈中最小的
                    local = dp[tt]*i;
                else
                    local = dp[tt]*(i-st.top()-1);
                if(local > ans)
                    ans = local;
            }
            else
            {
                st.push(i++);   //是下标入栈
            }
        }
        return ans;
    }
};
