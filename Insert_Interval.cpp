/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    // 一个基本的思路是：边扫描，边合并。后面合并的Interval不会对前面的结果造成影响
    // 另外一个就是要注意边界问题，还有判断两个Interval是否有交集的问题
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
    {
        int n = intervals.size();
        vector<Interval> ans;
        
        int state = 0;  //标记newInterval是否已经处理。可以很好的处理边界和空集的问题
        for(int i=0; i<intervals.size(); )
        {
            if(state==0 && helper(intervals[i], newInterval)==true)
            {
                state = 1;
                int start = min(intervals[i].start, newInterval.start);
                int end = max(intervals[i].end, newInterval.end);
                Interval tt(start, end);
                ++i;
                while(i < intervals.size())
                {
                    if(helper(intervals[i], tt)==true)
                    {
                        start = min(intervals[i].start, tt.start);
                        end = max(intervals[i].end, tt.end);
                        tt.start = start;
                        tt.end = end;
                        ++i;
                    }
                    else
                    {
                        break;
                    }
                }
                ans.push_back(tt);
            }
            // 虽然不相交，但是有可能该newInterval位于当前Interval的前面,次序还是不能乱的
            else if(state==0 && newInterval.end < intervals[i].start)
            {
                ans.push_back(newInterval);
                state = 1;
            }
            else
            {
                ans.push_back(intervals[i]);
                ++i;
            }
        }
        if(state==0)
            ans.push_back(newInterval);
        
        return ans;
    }
    // 判断两个Interval是否相交
    bool helper(Interval &a, Interval &b)
    {
        if(a.start>=b.start && a.start<=b.end)
            return true;
        else if(a.end>=b.start && a.end<=b.end)
            return true;
        else if(a.start < b.start && a.end > b.end) //b被a全包含
            return true;
        else   
            return false;
    }
};
