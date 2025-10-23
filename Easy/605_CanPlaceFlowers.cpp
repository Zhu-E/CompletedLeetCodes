class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int num = flowerbed.size();
        int cur = 0;
        for(int i = 0; i < num; ++i){
            if(flowerbed[i]==1){
                continue;
            }
            bool leftEmpty = false;
            bool rightEmpty = false;
            if(i==0||flowerbed[i-1]==0){
                leftEmpty=true;
            }
            if(i==num-1||flowerbed[i+1]==0){
                rightEmpty=true;
            }
            if(leftEmpty&&rightEmpty){
                flowerbed[i]=1;
                ++cur;
            }
        }
        return cur>=n;
    }
};
