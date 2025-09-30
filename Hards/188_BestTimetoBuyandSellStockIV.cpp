class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //DP With index, transactions done, currently own or not. Cell value is profit
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2,INT_MIN)));
        // dp[0][0][1]=-1*prices[0];
        dp[0][0][0]=0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < k+1; ++j){
                if(dp[i][j][0]!=INT_MIN){
                    //Buy or hold
                    dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][0]);
                    dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][0]-prices[i]);
                }
                if(dp[i][j][1]!=INT_MIN){
                    //Sell or hold
                    if(j+1<k+1){
                        dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][1]+prices[i]);
                    }
                    dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][1]);
                }

            }
        }
        // for(auto i : dp){
        //     for(auto j : i){
        //         cout<<j[0]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = 0;
        for(int i = 0; i < k+1; ++i){
            ans = max(ans, dp[n][i][0]);
        }
        return ans;
    }
};
