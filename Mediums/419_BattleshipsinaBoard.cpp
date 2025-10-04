class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int l = board.size();
        int w = board[0].size();
        vector<vector<bool>> visited(l, vector<bool>(w, false));
        int ans = 0;
        for(int i = 0; i < l; ++i){
            for(int j = 0; j < w; ++j){
                if(!visited[i][j]&&board[i][j]=='X'){
                    ++ans;
                    dfs(board, visited, i, j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y){
        if(x<0||y<0||x>=board.size()||y>=board[0].size()||visited[x][y]){
            return;
        }
        if(board[x][y]=='X'){
            visited[x][y]=true;
            dfs(board, visited, x+1,y);
            dfs(board, visited, x-1,y);
            dfs(board, visited, x,y-1);
            dfs(board, visited, x,y+1);
        }

    }
};
