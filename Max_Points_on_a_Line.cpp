/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    // 以每个点为单位，计算包含该点的所有直线中的最大点数
    // 从测试案例来看，不用去重，相同的结果有几个就算几个节点，面试的时候一定要问清楚
    int maxPoints(vector<Point> &points) 
    {
        // 充分利用数据结构unordered_map
        int ans = 0;
        unordered_map<double, int> ump;
        
        for(int i=0; i<points.size(); ++i)
        {
            ump.clear();    //每次使用时需要清空
            
            int local = 0;
            int column = 0; //当两个点垂直时，斜率无穷大，因此需要特殊处理
            int same = 0;   //记录和points[i]相同点的个数, 包括自身
            for(int j=0; j<points.size(); ++j)
            {
                //对相同节点要特别注意，因为其可以位于任意的直线上
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    same++;
                else if(points[i].x == points[j].x)  //垂直
                    column++;
                else
                {
                    // 这里呀特别注意：给定的x和y都是整数，在做出发时需要转换成浮点数
                    double k = (points[j].y-points[i].y)*1.0/(points[j].x-points[i].x);
                    ump[k]++;
                }
            }
            for(unordered_map<double, int>::iterator it=ump.begin(); it!=ump.end(); ++it)
            {
                if(it->second > local) 
                    local = it->second;
            }
            if(column > local)
                local = column;
            
            if(local+same > ans)
                ans = local+same;
        }
        return ans;
    }
};
