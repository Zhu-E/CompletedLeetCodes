class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> leastCandies(n, 0);
        vector<long long> mostCandies(n, 0);
        long long running = 0;
        for(int i = 0; i < n; ++i){
            leastCandies[i]=running+1;
            running+=candiesCount[i];
            mostCandies[i]=running;
        }
        vector<bool> ans;
        for(auto i : queries){
            if(i[1]+1<=mostCandies[i[0]]&&leastCandies[i[0]]<=(long long)i[2]*(i[1]+1)){
                ans.push_back(true);
                continue;
            }
            ans.push_back(false);
        }
        return ans;
    }
};
