class Solution {
public:
    // 这种做法，因为在循环处没有其他判断条件，会出现超时
    // 比如案例："aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"
    bool isMatch(const char *s, const char *p) 
    {
        if(s==NULL || p==NULL)  //我们规定非法指针统一为false
            return false;
        
        if(*p=='\0')    //当p为空时，s必须为空
            return *s=='\0';
        if(*s!='\0' && (*s==*p || *p=='?') )
            return isMatch(s+1, p+1);
        if(*p=='*')
        {
            if(isMatch(s, p+1)==true)   //处理匹配0个的情况
                return true;
            
            int i = 1;  //'*'的匹配数
            while(*(s+i-1)!='\0')   //若*(s+i-1)不等于'\0', 那么*(s+i)最多等于'\0'
            {
                if(isMatch(s+i, p+1)==true)
                    return true;
                ++i;
            }
            return false;
        }
        return false;
    }
};
