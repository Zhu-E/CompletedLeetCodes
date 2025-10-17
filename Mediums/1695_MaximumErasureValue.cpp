class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int curScore = 0;
        int maxScore = 0;
        int n = nums.size();
        unordered_set<int> current;
        while(r<n){
            while(current.count(nums[r])==1){
                current.erase(nums[l]);
                curScore-=nums[l];
                ++l;
            }
            curScore+=nums[r];
            current.insert(nums[r]);
            ++r;
            maxScore=max(maxScore, curScore);
        }
        return maxScore;
    }
};
