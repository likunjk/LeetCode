class Solution {
public:
    
    int isPalindrome(string &s, int left, int right, vector<vector<int> > &mp)
    {
        if(mp[left][right] != -1)   //采用备忘录，能大量节省计算时间
            return mp[left][right];
            
        if(left == right)   //边界：只有一个元素
            return mp[left][right] = 1;
            
        if(left+1 == right) //边界：只有2个元素
            return mp[left][right] = (s[left]==s[right]);
            
        if(s[left] == s[right])
            return mp[left][right] = isPalindrome(s, left+1, right-1, mp);
        else
            return mp[left][right] = 0;
    }
    
    int helper(int start, int end, string &s, vector<int> &dp, vector<vector<int> > &mp)
    {
        if(start > end) //处理边界，小心为上，比如s为空串的情况
            return 0;
            
        if(dp[start] != -1) //采用备忘录，充分利用已经计算过的信息
            return dp[start];
        
        if(start == end)    //处理边界
            return dp[start] = 0;
            
        if(isPalindrome(s, start, end, mp)==1)  //本身就是一个回文串，那么直接返回
            return dp[start] = 0;
        
        int localMin = 0x7fffffff;
        for(int i=0; start+i < end; ++i)
        {
            if(isPalindrome(s, start, start+i, mp)==1)
            {
                int tt = helper(start+i+1, end, s, dp, mp);
                if(tt+1 < localMin)
                    localMin = tt+1;
                    
                if(localMin == 1)   //已经是最优的了，没必要再继续找下去
                    return dp[start] = 1;
            }
        }
        return dp[start] = localMin;
    }
    
    // 若是采用静态数组+memset初始化方法，效率还会提高
    int minCut(string s) 
    {
        int len = s.length();
        
        int n = len+9;  //多分配几个空间，也避免了当len=0的情况
        
        //因为是从前往后划分，所以dp[i]表示从下表i开始的后面所有字符串的最小划分数
        vector<int> dp(n, -1);  
        
        //mp[i][j]表示[i,j]范围内的字符串只是否回文串，初始为-1，表示还没确定
        vector<vector<int> > mp(n, vector<int>(n, -1));
        
        return helper(0, len-1, s, dp, mp);
    }
};
