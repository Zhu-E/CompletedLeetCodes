class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> vertPrefix(n, vector<int>(m,0));
        vector<vector<int>> horzPrefix(n, vector<int>(m,0));
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(j==0){
                    horzPrefix[i][j]=matrix[i][j];
                }
                else if(matrix[i][j]==0){
                    horzPrefix[i][j]=0;
                }
                else{
                    horzPrefix[i][j]=horzPrefix[i][j-1]+1;
                }
            }
        }
        for(int j = 0; j < m; ++j){
            for(int i = 0; i < n; ++i){
                if(i==0){
                    vertPrefix[i][j]=matrix[i][j];
                }
                else if(matrix[i][j]==0){
                    vertPrefix[i][j]=0;
                }
                else{
                    vertPrefix[i][j]=vertPrefix[i-1][j]+1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int topLeft = 0;
                if(i!=0&&j!=0){
                    topLeft = dp[i-1][j-1];
                }
                dp[i][j]=min(topLeft+1, vertPrefix[i][j]);
                dp[i][j]=min(dp[i][j], horzPrefix[i][j]);
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};
