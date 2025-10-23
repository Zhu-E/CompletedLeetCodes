class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n+1, 0);
        for(auto i : nums){
            counts[i]++;
        }
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n+1; ++i){
            if(counts[i]!=0){
                pq.push(pair<int, int>(counts[i], i));
            }
        }
        vector<vector<int>> ans(pq.top().first, vector<int>());
        while(!pq.empty()){
            pair<int, int> cur = pq.top();
            for(int i = 0; i < cur.first; ++i){
                ans[i].push_back(cur.second);
            }
            pq.pop();
        }
        return ans;
    }
};
