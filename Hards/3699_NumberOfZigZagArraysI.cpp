class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        // vector<vector<int>> dp(n, vector<int>(r-l+1, 1));
        vector<int> cur(r-l+1, 1);
        vector<int> prev(r-l+1, 1);
        for(int i = 0; i < n; ++i){
            if(i==0){
                prev[i]=1;
            }
            else if(i%2==0){
                for(int i = 0; i < r-l+1; ++i){
                    if(i==0){
                        prev[i]=cur[i];
                        cur[i]=0;
                    }
                    else{
                        prev[i]=cur[i];
                        cur[i]=(prev[i-1]+cur[i-1])%1000000007;
                    }
                }
            }
            else{
                for(int i = r-l; i >= 0; --i){
                    if(i==r-l){
                        prev[i]=cur[i];
                        cur[i]=0;
                    }
                    else{
                        prev[i]=cur[i];
                        cur[i]=(cur[i+1]+prev[i+1])%1000000007;
                    }
                }
            }
            // for(auto i : cur){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            // for(auto i : prev){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            // cout<<endl;
        }
        // for(int i = 1; i < n; ++i){
        //     if(i%2==1){
        //         for(int j = 0; j < r-l+1; ++j){
        //             if(j==0){
        //                 dp[i][j]=0;
        //             }
        //             else{
        //                 dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%1000000007;
        //             }
        //         }
        //     }
        //     else{
        //         for(int j = r-l; j >= 0; --j){
        //             if(j==r-l){
        //                 dp[i][j]=0;
        //             }
        //             else{
        //                 dp[i][j]=(dp[i][j+1]+dp[i-1][j+1])%1000000007;
        //             }
        //         }
        //     }
            
        // }
        int ans = 0;
        for(auto i : cur){
            ans = (ans+i)%1000000007;
        }

        // for(auto i : dp){
        //     for(auto j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return (2*ans)%1000000007;
    }
};
