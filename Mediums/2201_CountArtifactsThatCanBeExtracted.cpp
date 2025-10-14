class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<bool>> dug(n, vector<bool>(n, false));
        int ans = 0;
        int numDug = dig.size();
        for(int i = 0; i < numDug; ++i){
            dug[dig[i][0]][dig[i][1]] = true;
        }
        for(auto i : artifacts){
            bool dugUp=true;
            for(int j = i[0]; j <= i[2]; ++j){
                for(int k = i[1]; k<=i[3]; ++k){
                    if(dug[j][k]==false){
                        dugUp=false;
                        break;
                    }
                }
                if(!dugUp){
                    break;
                }
            }
            if(dugUp){
                ++ans;
            }
        }
        return ans;
    }
};
