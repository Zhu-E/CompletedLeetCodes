class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int numStrs = strs.size();
        vector<vector<vector<int>>> dp(numStrs+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        vector<int> zeroes;
        vector<int> ones;
        for(auto str : strs){
            zeroes.push_back(countZeroes(str));
            ones.push_back(countOnes(str));
        }
        int ans = 0;
        dp[0][0][0]=0;
        for(int i = 0; i < numStrs; ++i){
            for(int a = 0; a < m+1; ++a){
                for(int b = 0; b < n+1; ++b){
                    if(dp[i][a][b]!=-1){
                        dp[i+1][a][b]=max(dp[i][a][b], dp[i+1][a][b]);
                        if(a+zeroes[i]<=m&&b+ones[i]<=n){
                            dp[i+1][a+zeroes[i]][b+ones[i]]=max(dp[i][a][b]+1, dp[i+1][a+zeroes[i]][b+ones[i]]);
                            // ans = max(ans, dp[i+1][a][b]);
                            ans = max(ans, dp[i+1][a+zeroes[i]][b+ones[i]]);
                        }
                    }
                }
            }
        }
        return ans;
    }
    int countOnes(string str){
        int count = 0;
        for(auto i : str){
            if(i=='1'){
                ++count;
            }
        }
        return count;
    }
    int countZeroes(string str){
        int count = 0;
        for(auto i : str){
            if(i=='0'){
                ++count;
            }
        }
        return count;
    }
};
