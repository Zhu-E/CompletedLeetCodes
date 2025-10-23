class Solution {
public:
    int reverse(int x) {
        bool isNeg = x<0;
        int newNum = 0;
        if(x==INT_MIN){
            return 0;
        }
        x=abs(x);
        while(x>0){
            if(newNum>INT_MAX/10){
                return 0;
            }
            newNum*=10;
            if(newNum>INT_MAX-x%10){
                return 0;
            }
            newNum+=x%10;
            x/=10;
        }
        if(isNeg){
            return -1*newNum;
        }
        return newNum;
    }
};
