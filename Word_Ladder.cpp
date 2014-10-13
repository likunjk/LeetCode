class Solution {
public:
    struct Node
    {
        string str;
        int no;
        Node(){}
        Node(string s, int n):str(s),no(n){}
    };
    int ladderLength(string start, string end, unordered_set<string> &dict) 
    {
        if(start == end)    //初始值start等于end
            return 1;
        
        Node tt;
        queue<Node> q;
        unordered_set<string> data; //标记哪些字符串已经计算过
        
        q.push(Node(start,1));
        data.insert(start);
        
        while(!q.empty())
        {
            tt = q.front();
            q.pop();
            for(int i=0; i<tt.str.size(); ++i)  //每一次只能改变一位
            {
                string s = tt.str;  //拷贝一份，这样就不会破坏原字符串
                for(int j=0; j<26; ++j)
                {
                    s[i] = 'a'+j;
                    if(s == end)    //此处必须判断，有可能end字符串没有在dict中
                        return tt.no+1;
                    if(dict.find(s)!=dict.end() && data.find(s)==data.end())
                    {
                        data.insert(s); //忘记加入，导致内存超限
                        q.push(Node(s, tt.no+1));
                    }
                }
            }
        }
        return 0;
    }
};
