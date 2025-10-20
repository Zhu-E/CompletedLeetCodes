class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int total = 0;
        int cur = 0;
        for(auto i : nums){
            total+=i;
        }
        vector<int> ans;
        for(int i = n-1; i>=0; --i){
            cur+=nums[i];
            ans.push_back(nums[i]);
            if(cur>total/2){
                return ans;
            }
        }
        return ans;
    }
};
