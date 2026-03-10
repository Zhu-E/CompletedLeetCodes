class Solution {
public:
    int numberOfChild(int n, int k) {
        int period = (n-2)*2+2;
        int pos = k%period;
        if(pos < n){
            return pos;
        }
        else{
            return n-1-pos%(n-1);
        }
    }
};
