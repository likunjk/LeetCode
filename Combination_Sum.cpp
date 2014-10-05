class Solution {
public:
    // 这道题是关于组合的经典题目，每个数字可以取任意多次
    // 相应的题目保证了给定的数组中没有重复元素，并且每个元素都是正数
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {
        vector<vector<int> > ans;
        vector<int> tmp;
        
        sort(candidates.begin(), candidates.end());
        helper(ans, candidates, tmp, target, 0, 0);
        
        return ans;
    }
    // k--现在该选哪一个数字   sum--已经选出数字的和
    void helper(vector<vector<int> > &ans, vector<int> &candidates, vector<int> &tmp, int target, int k, int sum)
    {
        if(k >= candidates.size())
            return;
        
        for(int i=0; ; ++i)
        {
            if(sum + candidates[k]*i <= target)
            {
                sum += candidates[k]*i;
                for(int j=0; j<i; ++j)
                    tmp.push_back(candidates[k]);
                    
                if(sum == target)
                    ans.push_back(tmp);
                else
                    helper(ans, candidates, tmp, target, k+1, sum);
                
                for(int j=0; j<i; ++j)
                    tmp.pop_back();
                sum -= candidates[k]*i;
            }
            else
            {
                break;
            }
        }
    }
};
