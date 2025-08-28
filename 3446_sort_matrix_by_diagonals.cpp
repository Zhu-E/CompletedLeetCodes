class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; ++i){
            vector<int> curDiag;
            int curX=i;
            int curY=0;
            while(curX<n){
                curDiag.push_back(grid[curX][curY]);
                ++curX;
                ++curY;
            }
            sort(curDiag.begin(),curDiag.end(),greater<int>());
            curX=i;
            curY=0;
            while(curX<n){
                grid[curX][curY]=curDiag[curY];
                ++curY;
                ++curX;
            }
        }
        for(int i = 1; i < m; ++i){
            vector<int> curDiag;
            int curX=0;
            int curY=i;
            while(curY<n){
                curDiag.push_back(grid[curX][curY]);
                ++curX;
                ++curY;
            }
            sort(curDiag.begin(),curDiag.end());
            curX=0;
            curY=i;
            while(curY<n){
                grid[curX][curY]=curDiag[curX];
                ++curX;
                ++curY;
            }
        }
        return grid;
    }
};
