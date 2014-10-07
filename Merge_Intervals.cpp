/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool comp(const Interval &a, const Interval &b)
{
    if(a.start == b.start)
        return a.end < b.end;
    else
        return a.start < b.start;
}
 
class Solution {
public:
    // 这道题应该算是前面Insert Interval的加强版
    // 解决思路还是一样的，边扫描，边合并
    vector<Interval> merge(vector<Interval> &intervals) 
    {
        // 给定的vector不保证有序，并且可能还有重复元素
        sort(intervals.begin(), intervals.end(), comp); 
        
        int n = intervals.size();
        vector<Interval> ans;
        
        int i = 0;
        for(i=0; i+1<n; )   //要注意边界条件
        {
            if(helper(intervals[i], intervals[i+1])==true)
            {
                // 若一个Interval跟后面的Interval有交集，那么在合并之后，继续合并，直到不能合并为止
                int start = min(intervals[i].start, intervals[i+1].start);
                int end = max(intervals[i].end, intervals[i+1].end);
                Interval tt(start, end);
                i += 2;
                while(i<n && helper(tt, intervals[i])==true)
                {
                    start = min(tt.start, intervals[i].start);
                    end = max(tt.end, intervals[i].end);
                    tt.start = start;
                    tt.end = end;
                    ++i;
                }
                ans.push_back(tt);
            }
            else
            {
                ans.push_back(intervals[i]);
                ++i;
            }
        }
        
        if(i==n-1)  //最后一个元素，直接压入
            ans.push_back(intervals[i]);
            
        return ans;
    }
    
    bool helper(Interval &a, Interval &b)
    {
        if(a.start>=b.start && a.start<=b.end)
            return true;
        else if(a.end>=b.start && a.end<=b.end)
            return true;
        else if(a.start<b.start && a.end>b.end)
            return true;
        else
            return false;
    }
};
