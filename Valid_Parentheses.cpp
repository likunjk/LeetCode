class Solution {
public:
    // 无论是一种括号，还是3种括号，策略都是一样的：
    // 遇到左括号入栈，右括号则与栈顶元素比较，不匹配则不合法。最后再判断栈是否为空
    bool isValid(string s) 
    {
        stack<char> st;
        for(int i=0; i<s.length(); ++i)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else
            {
                if(st.empty())  //若此时栈为空，则不合法
                    return false;
                if(s[i]==')')
                {
                    if(st.top()!='(')
                        return false;
                }
                else if(s[i]==']')
                {
                    if(st.top()!='[')
                        return false;
                }
                else
                {
                    if(st.top()!='{')
                        return false;
                }
                st.pop();   //当匹配时，都需要弹栈操作
            }
        }
        if(st.empty()) //若要合法，最后栈必须为空
            return true;
        else
            return false;
    }
};
