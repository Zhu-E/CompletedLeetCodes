class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int lastCut = 0;
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int maxHorz=0;
        int maxVert=0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for(auto i : horizontalCuts){
            maxHorz = max(maxHorz, i-lastCut);
            lastCut = i;
        }
        lastCut = 0;
        for(auto i : verticalCuts){
            maxVert = max(maxVert, i-lastCut);
            lastCut = i;
        }
        return ((long long)maxVert*maxHorz)%1000000007;
    }
};
