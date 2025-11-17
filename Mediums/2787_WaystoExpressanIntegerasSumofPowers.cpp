class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> vals;
        int curBase = 1;
        int cur = 1;
        while(cur <= n){
            cur=curBase;
            for(int i = 1; i < x; ++i){
                cur *= curBase;
            }
            if(cur<=n){
                vals.push_back(cur);
            }
            curBase++;
        }
        int numVals = vals.size();
        // for(auto i : vals){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        vector<vector<int>> dp(numVals, vector<int>(n+1, 0));
        dp[0][0]=1;
        dp[0][1]=1;
        for(int i = 0; i < numVals-1; ++i){
            for(int j = 0; j < n+1; ++j){
                // cout<<dp[i][j]<<" ";
                int nextVal = j+vals[i+1];
                if(nextVal<=n){
                    dp[i+1][nextVal]+=dp[i][j];
                    dp[i+1][nextVal]%=1000000007;
                }
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=1000000007;
            }
            // cout<<endl;
        }
        return dp[numVals-1][n];
    }
    
    
};
