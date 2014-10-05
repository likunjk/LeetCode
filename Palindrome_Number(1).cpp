class Solution {
public:
    // 一个很直接的思路：先求出这个数有多少位，然后分别取最高位和最低位比较
    bool isPalindrome(int x) 
    {
        if(x < 0)   //对于负数需要特殊处理
            return false;
        
        int count = 0;  //记录该数有多少位
        int tt = x;
        while(tt)
        {
            count++;
            tt /= 10;
        }
        for(int i=0, j=count-1; i<j; ++i,--j)   //完全模拟字符串的比较
        {
            int t1 = ( x / myPower(10,i) ) % 10;
            int t2 = ( x / myPower(10,j) ) % 10;
            if(t1!=t2)
                return false;
        }
        return true;
    }
    
    int myPower(int a, int n)   //自己定义的快速幂乘函数
    {
        if(n==0)
            return 1;
        int ans = myPower(a, n/2);
        if(n&1)
            return ans*ans*a;
        else
            return ans*ans;
    }
};
