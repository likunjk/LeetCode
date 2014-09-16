class Solution {
public:
    // 模拟题，采用堆栈解决
    int evalRPN(vector<string> &tokens) 
    {
        int n = tokens.size();
        
        stack<int> st;
        
        for(int i=0; i<n; ++i)
        {
            string s = tokens[i];
            
            //这里只能是先判断是否为操作符，因为整数的情况太多，并且'-'也有不同的含义
            if(s=="+" || s=="-" || s=="*" || s=="/")    
            {
                // 当遇到运算符时，弹出栈顶的两个数进行运算，然后将结果压栈
                // 要特别注意，先弹出的是第2个操作数
                int t2 = st.top();  
                st.pop();
                int t1 = st.top();
                st.pop();
                
                if(s[0]=='+')
                    st.push(t1+t2);
                else if(s[0]=='-')
                    st.push(t1-t2);
                else if(s[0]=='*')
                    st.push(t1*t2);
                else if(s[0]=='/')
                    st.push(t1/t2);
            }
            else
            {
                int tt = atoi(s.c_str());   //使用库函数进行转换
                st.push(tt);
            }
        }
        
        return st.top();
    }
};
