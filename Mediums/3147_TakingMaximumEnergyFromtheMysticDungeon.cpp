class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> possible(k, 0);
        int n = energy.size();
        for(int i = 0; i < n; ++i){
            possible[i%k]=max(energy[i],possible[i%k]+energy[i]);

        }int ans = INT_MIN;
        for(auto i : possible){
            ans = max(ans, i);
        }
        return ans;
    }
};
