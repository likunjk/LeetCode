class Solution {
public:
    // 这个题跟前面一道题类似，也有区别：每次元素只能选取有限多次
    // 如果仔细读题的话，可以发现，题目的描述还是很严谨的。前面说的是Given a set of candidate numbers
    // 这一道题是Given a collection of candidate numbers
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        vector<vector<int> > ans;
        vector<int> tmp;
        
        sort(num.begin(), num.end());
        helper(num, target, ans, tmp, 0, 0);
        
        return ans;
    }
    
    void helper(vector<int> &num, int target, vector<vector<int> > &ans, vector<int> &tmp, int k, int sum)
    {
        if(k >= num.size())
            return ;
        int count = 1;
        // 寻找有几个相同的数，先找出来再进行枚举
        while(k+1<num.size() && num[k]==num[k+1])
        {
            count++;
            k++;
        }
        // 枚举元素num[k]出现次数
        for(int i=0; i<=count; ++i) //这里一定要取到等号
        {
            if(sum + num[k]*i <= target)
            {
                sum += num[k]*i;
                for(int j=0; j<i; ++j)
                    tmp.push_back(num[k]);
                if(sum == target)
                    ans.push_back(tmp);
                else
                    helper(num, target, ans, tmp, k+1, sum);
                // 恢复现场
                for(int j=0; j<i; ++j)
                    tmp.pop_back();
                sum -= num[k]*i;
            }
            else
            {
                break;
            }
        }
    }
};
