class Solution {
public:
    int numSub(string s) {
        int streak = 0;
        int ans = 0;
        for(auto c : s){
            if(c=='1'){
                ++streak;
            }
            else{  
                // cout<<streak<<" ";
                ans = (ans+triangular(streak))%1000000007;
                streak = 0;
            }
        }
        ans = (ans+triangular(streak))%1000000007;
        return ans;
    }
    int triangular(int n){
        return ((long long)n*(n+1)/2)%1000000007;
    }
};
