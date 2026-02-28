class Solution {
public:
    int concatenatedBinary(int n) {
        if(n==1){
            return 1;
        }
        int shift = 0;
        int temp = n;
        int prev = concatenatedBinary(n-1);
        while(temp>0){
            prev = prev<<1;
            prev = prev%1000000007;
            temp /= 2;
        }
        return prev+n;
    }
};
