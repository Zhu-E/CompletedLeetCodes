class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> count;
        for(auto i:nums){
            count[i]++;
        }
        int max_freq=0;
        for(auto i : count){
            max_freq=max(max_freq,i.second);
        }
        int ans = 0;
        for(auto i : count){
            if(i.second==max_freq){
                ans+=max_freq;
            }
        }
        return ans;
    }
};
