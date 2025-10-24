class Solution {
public:
    bool isBalanced(int n){
        vector<int> counts(10, 0);
        while(n>0){
            counts[n%10]++;
            n/=10;
        }
        if(counts[0]!=0){
            return false;
        }
        for(int i = 0; i < 10; ++i){
            if(counts[i]!=0&&i!=counts[i]){
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for(int i = n+1; i <= 1224444; ++i){
            if(isBalanced(i)){
                return i;
            }
        }
        return -1;
    }
};
