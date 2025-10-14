class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prevDecrease = 0;
        int n = nums.size();
        int lastSequence = 0;
        int curSequence = 1;
        for(int i = 1; i < n; ++i){
            if(nums[i]>nums[i-1]){
                ++curSequence;
            }
            else{
                if((lastSequence>=k&&curSequence>=k)||curSequence>=2*k){
                    return true;
                }
                lastSequence = curSequence;
                curSequence = 1;
            }
        }
        if(curSequence>=2*k||lastSequence>=k&&curSequence>=k){
            return true;
        }
        return false;
    }
};
