class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int minSeen = INT_MAX;
        for(int i = 0; i < n; ++i){
            ans = max(ans, nums[i]-minSeen);
            minSeen = min(minSeen, nums[i]);
        }
        if(ans == 0){
            return -1;
        }
        return ans;
    }
};
