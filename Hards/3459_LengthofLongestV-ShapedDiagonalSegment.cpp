class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        vector<vector<int>> dirs({{-1, 1}, {1, 1}, {1, -1}, {-1, -1}});
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> noChangeDp(n, vector<vector<int>>(m, vector<int>(4, 0))); // dp[i][j][k] i is row j is column k is direction value is longest diagonal with specifications 
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(4, 0))); 
        for(int dir = 0; dir < 4; ++dir){
            int startX;
            int startY;
            if(dirs[dir][0]==1){
                startX = n-1;
            }
            else{
                startX = 0;
            }
            if(dirs[dir][1]==1){
                startY = m-1;
            }
            else{
                startY = 0;
            }
            for(int i = startX; i >= 0 && i < n; startX == 0 ? ++i : --i){
                for(int j = startY; j >= 0 && j < m; startY == 0 ? ++j : --j){
                    if(grid[i][j]==1){
                        noChangeDp[i][j][dir]=0;
                        continue;
                    }
                    else if(i==startX||j==startY){
                        noChangeDp[i][j][dir]=1;
                        continue;
                    }
                    int prevX = i+dirs[dir][0];
                    int prevY = j+dirs[dir][1];
                    if(grid[i][j]!=grid[prevX][prevY]&&grid[prevX][prevY]!=1){
                        noChangeDp[i][j][dir]=noChangeDp[prevX][prevY][dir]+1;
                    }
                    else{
                        noChangeDp[i][j][dir]=1;
                    }
                }
            }
        }
        for(int dir = 0; dir < 4; ++dir){
            // cout<<"DIRECTION IS "<<dir<<endl;
            int startX;
            int startY;
            if(dirs[dir][0]==1){
                startX = n-1;
            }
            else{
                startX = 0;
            }
            if(dirs[dir][1]==1){
                startY = m-1;
            }
            else{
                startY = 0;
            }
            for(int i = startX; i >= 0 && i < n; startX == 0 ? ++i : --i){
                for(int j = startY; j >= 0 && j < m; startY == 0 ? ++j : --j){
                    if(grid[i][j]==1){
                        dp[i][j][dir]=0;
                        // cout<<"  1   ";
                        continue;
                    }
                    else if(i==startX||j==startY){
                        dp[i][j][dir]=1;
                        // continue;
                    }
                    int prevX = i+dirs[dir][0];
                    int prevY = j+dirs[dir][1];
                    if(inRange(prevX, prevY, n, m)&&grid[i][j]!=grid[prevX][prevY]&&grid[prevX][prevY]!=1){
                        dp[i][j][dir]=max(dp[i][j][dir],dp[prevX][prevY][dir]+1);
                    }
                    int nextDir = (dir+1)%4;
                    prevX = i+dirs[nextDir][0];
                    prevY = j+dirs[nextDir][1];
                    if(inRange(prevX,prevY,n,m)&&grid[i][j]!=grid[prevX][prevY]&&grid[prevX][prevY]!=1){
                        dp[i][j][dir]=max(dp[i][j][dir],noChangeDp[prevX][prevY][nextDir]+1);
                    }
                    dp[i][j][dir]=max(dp[i][j][dir], 1);
                    // cout<<dp[i][j][dir]<<","<<prevX<<","<<prevY<<" ";
                }
                // cout<<endl;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j]==1){
                    ans = max(ans, 1);
                    for(int dir = 0; dir < 4; ++dir){
                        int newX = i+dirs[dir][0];
                        int newY = j+dirs[dir][1];
                        if(inRange(newX,newY,n,m)&&grid[newX][newY]==2){
                            ans = max(ans, dp[newX][newY][dir]+1);
                        }
                    }
                }
            }
        }
        // return 0;
        return ans;
    }
    bool inRange(int x, int y, int a, int b){
        return x>=0&&x<a&&y>=0&&y<b;
    }
};
