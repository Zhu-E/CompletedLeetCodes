class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> curStep;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        curStep.push(pair<int, int>(0, 0));
        int ans = 0;
        vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(true){
            queue<pair<int, int>> nextStep;
            while(!curStep.empty()){
                int x = curStep.front().first;
                int y = curStep.front().second;
                curStep.pop();
                if(visited[x][y]){
                    continue;
                }
                visited[x][y]=true;
                if(x==n-1&&y==m-1){
                    return ans;
                }
                for(auto i : dirs){
                    int newX = x+i[0];
                    int newY = y+i[1];
                    if(newX<0||newX>=n){
                        continue;
                    }
                    if(newY<0||newY>=m){
                        continue;
                    }
                    if(grid[newX][newY]==0){
                        curStep.push(pair<int, int>(newX, newY));
                    }
                    else{
                        nextStep.push(pair<int, int>(newX, newY));
                    }
                }
            }
            ++ans;
            curStep=nextStep;
        }
        return ans;
    }
};
