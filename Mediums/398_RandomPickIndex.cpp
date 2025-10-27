class Solution {

private:
unordered_map<int, vector<int>> dict;

public:
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            dict[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> indices = dict[target];
        int randIndex = rand()%indices.size();
        return dict[target][randIndex];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
