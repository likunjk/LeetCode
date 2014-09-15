class Solution {
public:

    int isPaindrome(string &s, int left, int right, vector<vector<int> > &mp)
    {
        if(mp[left][right] != -1)
            return mp[left][right];
        
        if(left == right)
            return mp[left][right] = 1;
            
        if(left+1 == right)
            return mp[left][right] = (s[left]==s[right]);
        
        if(s[left] == s[right])
            return mp[left][right] = isPaindrome(s, left+1, right-1, mp);
        else
            return mp[left][right] = 0;
    }
    void helper(int start, int end, string &s, vector<string> &dp, vector<vector<string> > &ans, vector<vector<int> > &mp)
    {
        if(start > end) //处理极端情况，比如s为空串
            return ;
        
        //  有可能当前求的这一段就是回文，因此加入结果集中，但是要再弹出来，不影响下面的结果
        //  该if语句同时也可作为递归的结束条件，当只有一个字符时，后面的for循环将不再执行
        if(isPaindrome(s, start, end, mp)==1)
        {
            dp.push_back(s.substr(start, end-start+1));
            ans.push_back(dp);
            dp.pop_back();
        }
        
        for(int i=0; start+i<end; ++i)  //这里必须是start+i < end
        {
            if(isPaindrome(s, start, start+i, mp)==1)
            {
                dp.push_back(s.substr(start, i+1));
                helper(start+i+1, end, s, dp, ans, mp);
                dp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        int len = s.length();
        int n = len+9;
        
        vector<string> dp; //保存每一趟的结果
        vector<vector<string> > ans;    //保存全部结果
        
        //  用于备忘
        vector<vector<int> > mp(n, vector<int>(n, -1));
        
        helper(0, len-1, s, dp, ans, mp);
        
        return ans;
    }
};
