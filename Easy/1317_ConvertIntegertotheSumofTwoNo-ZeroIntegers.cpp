class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; ++i){
            int left = i;
            int right = n-left;
            if((to_string(left)+to_string(right)).find('0')==string::npos){
                return {left, right};
            }
        }
        return {};
    }
};
