class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        unordered_map<int, int> counts;
        set<int> elements;
        int i;
        for(i = 0; i < k; ++i){
            ++counts[nums[i]];
            elements.insert(nums[i]);
        }
        vector<int> ans;
        int n = nums.size();
        while(i<=n){
            int cur = 0;
            auto it = elements.begin();
            int curElement;
            while(cur<x){
                cur+=counts[*it];
                curElement=*it;
                ++it;
            }
            if(curElement<0){
                ans.push_back(curElement);
            }
            else{
                ans.push_back(0);
            }
            counts[nums[i-k]]--;
            if(counts[nums[i-k]]==0){
                elements.erase(nums[i-k]);

            }
            if(i<n){
                counts[nums[i]]++;
                elements.insert(nums[i]);
            }
            ++i;
        }
        return ans;
    }
};
