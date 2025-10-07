class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN)); //dp[i][j] is the max value for the ith index jth timestep
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                if(j==0){
                    dp[i][j] = satisfaction[i];
                    if(i!=0){
                        dp[i][j]=max(dp[i][j], dp[i-1][j]);
                    }
                }
                else{
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+satisfaction[i]*(j+1)); //Include
                    dp[i][j] = max(dp[i][j], dp[i-1][j]); //Don't include
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans = max(ans, dp[n-1][i]);
        }
        return ans;
    }

};
