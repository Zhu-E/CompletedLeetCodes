class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> seen;
        for(auto i : nums){
            seen.insert(i);
            while(seen.count(original)!=0){
                original*=2;
            }
        }
        return original;
    }
};
