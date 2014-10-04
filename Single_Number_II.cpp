class Solution {
public:
    // 采用最通用的做法，统计二进制位上1的个数, 然后将其对3取余
    int singleNumber(int A[], int n) 
    {
        int ans = 0;
        for(int i=0; i<32; ++i)
        {
            int tt = 0;
            for(int j=0; j<n; ++j)
            {
                tt += (A[j]>>i)&1;  //赋值运算符的优先级倒数第2，只比逗号运算符高
            }
            ans |= (tt%3)<<i;   //不用去考虑符号位
        }
        
        return ans;
    }
};
