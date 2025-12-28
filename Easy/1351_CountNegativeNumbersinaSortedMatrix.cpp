class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int col = 0;
        int n = grid.size();
        int width = grid[0].size();
        int ans = 0;
        for(int i = n-1; i >= 0; --i){
            while(col<width&&grid[i][col]>-1){
                ++col;
            }
            if(col==width){
                return ans;
            }
            else{
                ans += width-col;
            }
        }
        return ans;
    }
};
