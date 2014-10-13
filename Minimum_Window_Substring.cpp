class Solution 
{
public:
    // 先找到一个满足条件的区间，然后尝试移动左边的指针，直到不能移动了为止
    // 复杂度为O(n), 因为内层的循环总共只进行了n次
    string minWindow(string S, string T) 
    {
        int data1[256], data2[256];
        memset(data1, 0, sizeof(data1));
        memset(data2, 0, sizeof(data2));
        
        for(int i=0; i<T.length(); ++i)
        {
            data1[T[i]]++;
            data2[T[i]]++;
        }
        int diff = 0;   //统计T中有多少个不同的字符
        for(int i=0; i<256; ++i)
        {
            if(data1[i]!=0)
                diff++;
        }
        int count = 0;  //记录当前已经出现了S中的多少个字符（每个字符都要出现T中出现的次数以上，才叫完全出现）
        int minLen = 0x7fffffff;
        string ans = "";
        for(int i=0,j=0; j<S.length(); ++j)
        {
            char ch = S[j];
            if(data1[ch] > 0)
            {
                --data2[ch];
                if(data2[ch]==0)    //说明T中的一个字符已经全部出现啦，happy呀
                    count++;
            }
            if(count>=diff) //此处必须是大于等于，因为后面count还可能被++，但是对判断结果没有影响
            {
                while(true)
                {
                    if(data1[S[i]] > 0) //当前字符是T中出现的
                    {
                        if(data2[S[i]]+1<=0)  //说明当前位置的字符是可以直接去掉的
                        {
                            data2[S[i]]++;
                            ++i;
                        }
                        else
                            break;
                    }
                    else
                        ++i;
                }
                if(j-i+1<minLen)
                {
                    minLen = j-i+1;
                    ans = S.substr(i,minLen);
                }
            }
        }
        return ans;
    }
};


