class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalParity = 0;
        for(auto i : nums){
            totalParity += i;
        }
        totalParity %= 2;
        int n = nums.size();
        if(!totalParity){
            return n-1;
        }
        return 0;
    }
};
