class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i][j][k] let i be index let j be number of transactions let k be whether a stock is held or not. The value at dp[i][j][k] is the maximum money given these conditions
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2,INT_MIN)));
        dp[0][0][0]=0;
        dp[0][0][1]=-1*prices[0];
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 2; ++k){
                    if(k==0){
                        dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][0]); //Do nothing
                        if(j>0&&dp[i-1][j-1][1]!=INT_MIN){
                            dp[i][j][k]=max(dp[i][j][k], dp[i-1][j-1][1]+prices[i]); //Sell stock 
                        }
                    }
                    if(k==1){
                        dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k]); //Do nothing;
                        if(dp[i-1][j][k-1]!=INT_MIN){
                            dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]-prices[i]); //Buy stock;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 2; ++j){
                ans = max(ans, dp[n-1][i][j]);
            }
        }
        return ans;

    }
};
