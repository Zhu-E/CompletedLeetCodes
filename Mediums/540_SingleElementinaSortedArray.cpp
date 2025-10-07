class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto i : nums){
            if(seen.count(i)==1){
                seen.erase(i);
            }
            else{
                seen.insert(i);
            }
        }
        return *seen.begin();
    }
};
