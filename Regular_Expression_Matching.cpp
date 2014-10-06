class Solution {
public:
    // 经典的正则匹配，谷歌的面试题之一
    bool isMatch(const char *s, const char *p) 
    {
        if(s==NULL || p==NULL)
            return false;
        
        // p和s可以同时为空(\0, 不等同于NULL)，当p为空时，s必须为空; 当s为空时，p可为空也可不为空
        if( *p=='\0' )
            return *s=='\0';
        
        if( *(p+1)=='*' )
        {
            if(isMatch(s, p+2)==true)   //对0做特殊处理
                return true;
            
            int i = 1;  //'*'匹配的字符数，从1开始
            // 若当前位置不等于'\0', 则下一个位置最多等于'\0'
            while( *(s+i-1)!='\0' && ( *(s+i-1)==*p || *p=='.') )
            {
                if(isMatch(s+i, p+2)==true)
                    return true;
                ++i;
            }
            return false;
        }
        
        if( *s!='\0' && (*p==*s || *p=='.') )
            return isMatch(s+1, p+1);
        
        return false;
    }
};
