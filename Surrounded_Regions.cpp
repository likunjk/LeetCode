struct CPoint
{
    int x,y;
    CPoint(int _x, int _y):x(_x),y(_y){}
};

class Solution {
public:
    // 广搜，从外围突破，上下左右四个方向。标记那些从外围可以访问到的'O',
    // 最后再扫描一遍，将外围不能访问的'O'更改为'X'
    void solve(vector<vector<char>> &board) 
    {
        int direct[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        int n = board.size();
        if(n==0)
            return ;
        int m = board[0].size();
        if(m==0)
            return ;
        
        vector<vector<bool> > flag(n, vector<bool>(m, false));   //用于广搜标记该点是否已经访问
        for(int j=0; j<m; ++j)
        {
            if(board[0][j]=='O')
                BFS(direct, board, flag, 0, j, n, m);
            if(board[n-1][j]=='O')
                BFS(direct, board, flag, n-1, j, n, m);
        }
        for(int i=0; i<n; ++i)
        {
            if(board[i][0]=='O')
                BFS(direct, board, flag, i, 0, n, m);
            if(board[i][m-1]=='O')
                BFS(direct, board, flag, i, m-1, n, m);
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(board[i][j]=='O')
                    board[i][j] = 'X';
                else if(board[i][j]=='T')
                    board[i][j] = 'O';
            }
        }
    }
    
    void BFS(int direct[4][2], vector<vector<char>> &board, vector<vector<bool> > &flag, int x, int y, int n, int m)
    {
        if(flag[x][y]==true)
            return;
        
        queue<CPoint> q;
        q.push(CPoint(x,y));
        flag[x][y] = true;  //进入队列时标记已访问
        if(board[x][y]=='O')
            board[x][y] = 'T';
        while(!q.empty())
        {
            CPoint tt = q.front();
            q.pop();
            for(int i=0; i<4; ++i)
            {
                x = tt.x+direct[i][0];
                y = tt.y+direct[i][1];
                if(isLegal(x,y,n,m)==true && flag[x][y]==false && board[x][y]=='O')
                {
                    flag[x][y] = true;
                    board[x][y] = 'T';
                    q.push(CPoint(x,y));
                }
            }
        }
    }
    
    bool isLegal(int x, int y, int n, int m)
    {
        if(x>=0 && x<n && y>=0 && y<m)
            return true;
        else
            return false;
    }
};
