class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        for(auto i : points){
            for(auto j : points){
                if(j[1]>=i[1]&&j[0]<=i[0]&&i!=j){
                    bool noPointsInside=true;
                    for(auto k : points){
                        if(k[0]>=j[0]&&k[0]<=i[0]&&k[1]>=i[1]&&k[1]<=j[1]&&k!=i&&k!=j){
                            noPointsInside=false;
                            break;
                        }
                    }
                    if(noPointsInside){
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};
