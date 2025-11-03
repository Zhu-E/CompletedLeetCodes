class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int maxTime = neededTime[0];
        int runningSum = neededTime[0];
        int n = neededTime.size();
        for(int i = 1; i < n; ++i){
            if(colors[i]==colors[i-1]){
                maxTime = max(maxTime, neededTime[i]);
                runningSum += neededTime[i];
            }
            else{
                ans += runningSum-maxTime;
                runningSum = neededTime[i];
                maxTime = neededTime[i];
            }
        }
        ans+=runningSum-maxTime;
        return ans;
    }
};
