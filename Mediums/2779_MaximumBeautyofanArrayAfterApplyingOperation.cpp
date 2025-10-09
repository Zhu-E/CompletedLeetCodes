class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> difference(100002, 0);
        for(auto i : nums){
            difference[max(0,i-k)]++;
            difference[min(100001, i+k+1)]--;
        }
        int runningSum = 0;
        int maximum = 0;
        for(auto i : difference){
            runningSum += i;
            maximum=max(maximum, runningSum);
        }
        return maximum;
    }
};
