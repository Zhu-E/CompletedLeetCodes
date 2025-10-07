class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> collection;
        int ans = 0;
        int count = 0;
        for(int i = nums.size()-1; i>=0; --i){
            ++ans;
            if(nums[i]<=k&&collection.count(nums[i])==0){
                collection.insert(nums[i]);
                ++count;
            }
            if(count>=k){
                return ans;
            }
        }
        return -1;
    }
};
