class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9, unordered_set<int>());
        vector<unordered_set<int>> cols(9, unordered_set<int>());
        vector<unordered_set<int>> boxes(9, unordered_set<int>());
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j]=='.'){
                    continue;
                }
                if(rows[i].count(board[i][j]-'0')==1){
                    return false;
                }
                rows[i].insert(board[i][j]-'0');
                if(cols[j].count(board[i][j]-'0')==1){
                    return false;
                }
                cols[j].insert(board[i][j]-'0');
                int boxIndex=(i/3)*3+(j/3);
                if(boxes[boxIndex].count(board[i][j]-'0')==1){
                    return false;
                }
                boxes[boxIndex].insert(board[i][j]-'0');
            }
        } 
        return true;
    }
};
