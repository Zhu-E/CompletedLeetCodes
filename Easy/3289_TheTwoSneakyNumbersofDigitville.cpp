class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> ans;
        for(auto i : nums){
            if(seen.count(i)==1){
                ans.push_back(i);
            }
            else{
                seen.insert(i);
            }
        }
        return ans;
    }
};
