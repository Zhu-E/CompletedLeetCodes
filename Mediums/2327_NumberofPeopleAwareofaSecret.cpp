class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> state(forget, 0);
        state[0] = 1;
        for(int i = 0; i < n-1; ++i){
            long long toBeTold = 0;
            for(int j=forget-1; j > 0; --j){
                state[j]=state[j-1];
                if(j>delay-1){
                    toBeTold+=state[j];
                    toBeTold%=1000000007;
                }
            }
            state[0]=toBeTold;
        }
        long long ans = 0;
        for(int i = 0; i < forget; ++i){
            ans+=state[i];
        }
        return ans%1000000007;
    }
};
