class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevRow = 0;
        int ans = 0;
        for(auto i : bank){
            int curRow = 0;
            for(auto j : i){
                if(j=='1'){
                    ++curRow;
                }
            }
            if(curRow!=0){
                ans+=prevRow*curRow;
                prevRow=curRow;
            }
        }
        return ans;
    }
};
