class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftDif(n+1, 0);
        for(auto i : shifts){
            if(i[2]==0){
                shiftDif[i[0]]--;
                shiftDif[i[1]+1]++;
            }
            if(i[2]==1){
                shiftDif[i[0]]++;
                shiftDif[i[1]+1]--;
            }
        }
        int curShift = 0;
        for(int i = 0; i < n; ++i){
            curShift+=shiftDif[i];
            s[i]=((s[i]-'a'+curShift)%26+26)%26+'a';
            
        }
        return s;
    }
};
