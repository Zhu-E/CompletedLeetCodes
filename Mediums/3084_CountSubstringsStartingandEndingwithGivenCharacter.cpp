class Solution {
public:
    long long countSubstrings(string s, char c) {
        int count = 0;
        long long ans = 0;
        for(auto i : s){
            if(i==c){
                ++count;
                ans+=count;
            }
        }
        return ans;
    }
};
