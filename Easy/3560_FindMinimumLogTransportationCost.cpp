class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(k>=n&&k>=m){
            return 0;
        }
        if(n>k){
            return (long long)k*(n-k);
        }
        else{
            return (long long)k*(m-k);
        }
    }
};
