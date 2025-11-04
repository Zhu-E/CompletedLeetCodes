class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        vector<int> counts(51, 0);
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            counts[nums[r]]++;
            ++r;
        }
        while(r <= n){
            priority_queue<pair<int,int>> highestFreq;
            int cur = 0;
            for(int i = 1; i < 51; ++i){
                highestFreq.push({counts[i], i});
            }
            for(int i = 0; i < x; ++i){
                auto top = highestFreq.top();
                cur+=top.first*top.second;
                highestFreq.pop();
            }
            ans.push_back(cur);
            if(r!=n){
                counts[nums[r]]++;
                counts[nums[l]]--;
            }
            ++l;
            ++r;
        }

        return ans;
    }
};
