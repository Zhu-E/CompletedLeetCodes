class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int ans = 0;
        while(numBottles>0||emptyBottles>=numExchange){
            ans+=numBottles;
            emptyBottles+=numBottles;
            numBottles=0;
            if(emptyBottles>=numExchange){
                emptyBottles-=numExchange;
                ++numBottles;
                ++numExchange;
            }
        }
        return ans;
    }
};
