class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int smallestEnergy = INT_MAX;
        long long sumOfEnergies = 0;
        for(auto i : enemyEnergies){
            smallestEnergy = min(smallestEnergy, i);
            sumOfEnergies+=i;
        }
        if(smallestEnergy>currentEnergy){
            return 0;
        }
        return (long long)(sumOfEnergies+currentEnergy-smallestEnergy)/smallestEnergy;

    }
};
