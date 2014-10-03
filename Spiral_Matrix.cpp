class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) 
    {
        vector<int> ans;
        
        int n = matrix.size();
        if(n==0)    //个人习惯：n表示行，m表示列
            return ans;
        int m = matrix[0].size();
        if(m==0)
            return ans;
        ans.reserve(n*m);
        
        int xMin = 0, xMax = n-1;
        int yMin = 0, yMax = m-1;
        int x = 0, y = -1;  //为了方便统一处理，这里从(0,-1)开始
        while(true)
        {
            if(y+1 > yMax)
                break;
            while(y+1<=yMax)
                ans.push_back(matrix[x][++y]);
            yMax--;
            
            if(x+1 > xMax)
                break;
            while(x+1<=xMax)
                ans.push_back(matrix[++x][y]);
            xMax--;
            
            if(y-1 < yMin)
                break;
            while(y-1>=yMin)
                ans.push_back(matrix[x][--y]);
            yMin++;
            
            if(x-1 < xMin+1)  //这里需要特别注意
                break;
            while(x-1>=xMin+1)
                ans.push_back(matrix[--x][y]);
            xMin++;
        }
        return ans;
    }
};
