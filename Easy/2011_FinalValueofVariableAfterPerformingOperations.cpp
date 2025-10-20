class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(auto i : operations){
            if(i.find("-")!=string::npos){
                --ans;
            }
            else{
                ++ans;
            }
        }
        return ans;
    }
};
