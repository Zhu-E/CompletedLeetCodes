class Solution {
public:
    int countCollisions(string directions) {
        int curStreak = 0;
        bool justStarted = true;
        int ans = 0;
        for(char i : directions){
            if(i=='S'||i=='R'){
                justStarted = false;
            }
            if(i=='R'){
                ++curStreak;
            }
            if(i=='L'){
                if(justStarted){
                    continue;
                }
                ans += curStreak+1;
                curStreak = 0;
            }
            if(i=='S'){
                ans += curStreak;
                curStreak = 0;
            }
        }
        return ans;
    }
};
