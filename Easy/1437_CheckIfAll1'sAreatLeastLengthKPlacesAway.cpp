class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int curLen = k;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i]==1){
                if(curLen<k){
                    return false;
                }
                curLen = 0;
            }
            else{
                ++curLen;
            }
        }
        return true;
    }
};
