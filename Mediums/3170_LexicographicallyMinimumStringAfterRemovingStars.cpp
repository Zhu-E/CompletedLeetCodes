class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<priority_queue<int>> lastSeen(26, priority_queue<int>());
        vector<bool> deleted(n, false);
        for(int i = 0; i < n; ++i){
            if(s[i]!='*'){
                lastSeen[s[i]-'a'].push(i);
                continue;
            }
            for(int j = 0; j < 26; ++j){
                if(!lastSeen[j].empty()){
                    deleted[i]=true;
                    deleted[lastSeen[j].top()]=true;
                    lastSeen[j].pop();
                    break;
                }
            }
        }
        string ans = "";
        for(int i = 0; i < n; ++i){
            if(!deleted[i]){
                ans+=s[i];
            }
        }
        return ans;
    }
};
