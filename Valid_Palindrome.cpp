class Solution {
public:
    char isAlphanumeric(char ch)
    {
        if(ch>='A' && ch<='Z')
            return 'a'+(ch-'A');
        else if(ch>='0' && ch<='9')
            return ch;
        else if(ch>='a' && ch<='z')
            return ch;
        else    //其他字符返回0
            return 0;
    }
    // 直接使用首尾指针进行判断，只不过要注意大小写的问题
    bool isPalindrome(string s) 
    {
        int n = s.length();
        if(n==0)
            return true;
        
        for(int i=0, j=n-1; i<j; )
        {
            s[i] = isAlphanumeric(s[i]);
            s[j] = isAlphanumeric(s[j]);
            if(s[i]!=0 && s[j]!=0)
            {
                if(s[i]==s[j])
                {
                    ++i;
                    --j;
                }
                else
                    return false;
            }
            else    //忽略掉其他字符
            {
                if(s[i]==0)
                    ++i;
                if(s[j]==0)
                    --j;
            }
        }
        return true;
    }
};
