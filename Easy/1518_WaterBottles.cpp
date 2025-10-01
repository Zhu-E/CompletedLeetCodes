class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int numEmpty=0;
        while(numBottles>0){
            ans+=numBottles;
            numEmpty+=numBottles;
            numBottles=numEmpty/numExchange;
            numEmpty%=numExchange;
        }
        return ans;
    }
};
