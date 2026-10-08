class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, unordered_set<char>> poles;
        for(int i = 0; i < rings.size(); i+=2){
            poles[rings[i+1]-'0'].insert(rings[i]);
        } 
        int ans = 0;
        for(int i = 0; i < 10; ++i){
            if(poles[i].size()==3){
                ++ans;
            }
        }
        return ans;
    }
};
