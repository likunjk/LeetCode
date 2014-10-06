class Solution {
public:
    // 从给定函数的原型来看，x一定是某个整数的平方。
    // 可是实际上不是这样的。当给定2时，期望输出1
    int sqrt(int x) 
    {
        if(x==0)
            return 0;
        
        // 牛顿迭代法，a+x/a >= 2*(根号x)
        double a = x;
        double b = (a+x/a)/2;
        while(fabs(a-b) > 0.000001) //自己定义的误差区间，这道题只要求保留整数部分，精度还可以降低
        {
            a = b;
            b = (a+x/a)/2;
        }
        return (int)b;
    }
};
