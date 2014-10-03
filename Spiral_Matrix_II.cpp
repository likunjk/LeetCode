class Solution {
public:
    // 跟Spiral Matrix是一样的思路，这种题有好的思路很关键啊
    vector<vector<int> > generateMatrix(int n) 
    {
        // 假设给定的n合法, 即n>=1
        vector<vector<int> > ans(n, vector<int>(n,0));
        
        int xMin = 0, xMax = n-1;
        int yMin = 0, yMax = n-1;
        int x = 0, y = -1;
        int start = 1;
        while(true)
        {
            if(y+1 > yMax)
                break;
            while(y+1 <= yMax)
                ans[x][++y] = start++;
            yMax--;
            
            if(x+1 > xMax)
                break;
            while(x+1 <= xMax)
                ans[++x][y] = start++;
            xMax--;
            
            if(y-1 < yMin)
                break;
            while(y-1 >= yMin)
                ans[x][--y] = start++;
            yMin++;
            
            if(x-1 < xMin+1)
                break;
            while(x-1 >= xMin+1)
                ans[--x][y] = start++;
            xMin++;
        }
        return ans;
    }
};
