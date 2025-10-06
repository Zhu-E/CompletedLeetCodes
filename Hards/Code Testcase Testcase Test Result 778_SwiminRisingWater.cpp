class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = 0;
        int r = n*n;
        while(l <= r){
            int mid = l+(r-l)/2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            dfs(visited, grid, mid, 0, 0);
            if(visited[n-1][n-1]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    void dfs(vector<vector<bool>>& visited, vector<vector<int>>& grid, int height, int x, int y){
        if(x<0||y<0||x>=visited.size()||y>=visited.size()){
            return;
        }
        if(visited[x][y]||grid[x][y]>height){
            return;
        }
        visited[x][y]=true;
        dfs(visited, grid, height, x+1, y);
        dfs(visited, grid, height, x-1, y);
        dfs(visited, grid, height, x, y+1);
        dfs(visited, grid, height, x, y-1);
    }
};
