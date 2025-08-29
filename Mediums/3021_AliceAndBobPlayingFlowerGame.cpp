class Solution {
public:
    long long flowerGame(int n, int m) {
        long long evenTop=n/2;
        long long oddTop=n/2+n%2;
        long long evenBot=m/2;
        long long oddBot=m/2+m%2;
        return evenTop*oddBot+oddTop*evenBot;
    }
};
