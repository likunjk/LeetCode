class Solution {
public:
    // 第一个做法其实有很多冗余的地方，存在很大的提升空间
    bool isPalindrome(int x) 
    {
        if(x < 0)   //对于负数需要特殊处理
            return false;
        int base = 1;
        while(x/base >= 10) // 需保证x/base结果为个位数
            base *= 10;
        while(x)
        {
            int left = x/base;  //分别取左右数字
            int right = x%10;
            if(left != right)
                return false;
            x -= left*base; //分别消去左右数字
            x /= 10;
            base /= 100;    //因为1次消除了2位
        }
        return true;
    }
};
