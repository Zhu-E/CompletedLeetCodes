class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9){
            return "";
        }
        int num_nines = sum/9;
        int leftover = sum%9;
        string ans(num_nines, '9');
        if(num_nines==num){
            return ans;
        }
        ans += to_string(leftover);
        if(num_nines+1==num){
            return ans;
        }
        string fill(num-num_nines-1, '0');
        ans = ans + fill;
        return ans;
    }
};
