class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> curWindow;
        int n = nums.size();
        for(int i = 0; i < k; ++i){
            curWindow.insert(nums[i]);
        }
        for(int i = k; i < n; ++i){
            ans.push_back(*curWindow.rbegin());
            curWindow.erase(curWindow.find(nums[i-k]));
            curWindow.insert(nums[i]);
        }
        ans.push_back(*curWindow.rbegin());
        return ans;
    }
};
