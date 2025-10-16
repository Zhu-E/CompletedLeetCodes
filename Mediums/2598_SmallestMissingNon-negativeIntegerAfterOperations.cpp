class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> buckets(value, 0);
        for(auto i : nums){
            buckets[(i%value+value)%value]++;
        }
        int minPos = 0;
        int minVal = INT_MAX;
        for(int i = 0; i < value; ++i){
            if(buckets[i]<minVal){
                minVal = buckets[i];
                minPos = i;
            }
        }
        return value*minVal+minPos;
    }
};
