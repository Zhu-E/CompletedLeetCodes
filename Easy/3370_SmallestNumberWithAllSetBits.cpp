class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        while(n>0){
            ans = ans<<1;
            ++ans;
            n/=2;
        }
        ans = ans>>1;
        return ans;
    }
};
