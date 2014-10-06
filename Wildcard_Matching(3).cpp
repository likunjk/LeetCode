int dp[1009][1009];

class Solution {
public:
    bool isMatch(const char *s, const char *p) 
    {
        if(s==NULL || p==NULL)  //我们规定非法指针统一为false
            return false;
        const char *last = NULL;    //指向p最后遇到的一个'*'位置
        const char *s2 = NULL;  //指向'*'回退时s的下一个字符位置
        while(*s!='\0')
        {
            // 下面的顺序很重要
            if(*p=='\0')
            {
                if(last!=NULL)  //最后一根救命稻草
                {
                    p = last+1;
                    s = ++s2;
                }
                else
                    return false;
            }
            else if(*s==*p || *p=='?')  //常规比较
            {
                ++s;
                ++p;
            }
            else if(*p=='*')    //遇到'*'时要更新last和s2
            {
                last = p;    //默认不匹配任何字符
                s2 = s;
                ++p;
            }
            else if(last!=NULL)  //最后一根救命稻草
            {
                p = last+1;
                s = ++s2;
            }
            else
                return false;
        }
        
        while(*p=='*')  //消除后面连续的'*'
            ++p;
            
        return *p==0;
    }
    
};
