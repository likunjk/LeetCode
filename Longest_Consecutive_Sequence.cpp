class Solution {
public:
    int longestConsecutive(vector<int> &num) 
    {
        unordered_set<int> ust; //使用unordered_set记录出现的元素，同时也可过滤重复元素
        for(int i=0; i<num.size(); ++i)
            ust.insert(num[i]);
        
        int ans = 0;
        for(int i=0; i<num.size(); ++i)
        {
            int tt = 1;
            int left = num[i]-1;
            while(ust.find(left) != ust.end())  //先往左找
            {
                ust.erase(left);    //这里必须要删除，不然就会变成O（n*n）
                
                tt++;
                left--;
            }
            int right = num[i]+1;
            while(ust.find(right) != ust.end()) //再往右找
            {
                ust.erase(right);   //先删除
                
                tt++;
                right++;    //再增加
            }
            if(tt > ans)
                ans = tt;
        }
        return ans;
    }
};
