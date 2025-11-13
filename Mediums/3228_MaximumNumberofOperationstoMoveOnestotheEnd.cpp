class Solution {
public:
    int maxOperations(string s) {
        vector<int> clumps;
        int count = 0;
        char last = '0';
        for(auto i : s){
            if(i=='1'){
                ++count;
                last='1';
            }
            else if(last=='1'){
                clumps.push_back(count);
                count=0;
                last='0';
            }
        }
        int ans = 0;
        int n = clumps.size();
        for(int i = 0; i < n; ++i){
            ans+=clumps[i]*(n-i);
        }
        return ans;
    }
};
