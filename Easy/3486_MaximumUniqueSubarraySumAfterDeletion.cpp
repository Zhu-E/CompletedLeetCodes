class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int ans = 0;
        int n = nums.size();
        int maximum = INT_MIN;
        for(int i = 0; i < n; ++i){
            maximum=max(maximum, nums[i]);
            if(nums[i]>0&&seen.count(nums[i])==0){
                ans+=nums[i];
                seen.insert(nums[i]);
            }
        }
        if(maximum<0){
            return maximum;
        }
        return ans;
    }
};
