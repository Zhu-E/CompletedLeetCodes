class Solution {
public:
    bool isPerfectSquare(int num) {
        int n = 0;
        while((long)n*n<num){
            ++n;
        }
        return (long)n*n==num;
    }
};
