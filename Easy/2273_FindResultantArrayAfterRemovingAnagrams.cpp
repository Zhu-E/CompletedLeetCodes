class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        ans.push_back(words[0]);
        for(int i = 1; i < n; ++i){
            vector<int> first(26,0);
            vector<int> second(26,0);
            for(auto j : words[i]){
                first[j-'a']++;
            }
            for(auto j : words[i-1]){
                second[j-'a']++;
            }
            if(first!=second){
                ans.push_back(words[i]);           
            }
        }
        return ans;
    }
};
