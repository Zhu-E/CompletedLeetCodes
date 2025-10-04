class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int numPotions = potions.size();
        int potionPos = 0;
        vector<pair<int, int>> sortedSpells;
        for(int i = 0 ; i < n ; ++i){
            sortedSpells.push_back(pair<int, int>({spells[i], i}));
        }
        sort(sortedSpells.begin(), sortedSpells.end());
        vector<int> ans(n, 0);
        for(int i = n-1; i >= 0; --i){
            while(potionPos<numPotions&&(long long)(potions[potionPos])*sortedSpells[i].first<success){
                ++potionPos;
            }
            ans[sortedSpells[i].second]=numPotions-potionPos;
        }
        return ans;
    }
};
