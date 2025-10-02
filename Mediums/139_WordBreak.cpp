class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0]=true;
        for(int i = 0; i < n+1; ++i){
            if(dp[i]==true){
                // cout<<"RUNNING FOR "<<i<<endl;
                for(auto word : wordDict){
                    int length = word.size();
                    if(i+length<n+1&&s.substr(i, length)==word){
                        // cout<<"CHECKING "<<word<<endl;
                        dp[i+length]=true;
                    }
                }
            }
        }
        // for(auto i : dp){
        //     cout<<i<<" ";
        // }
        return dp[n];
    }
};
