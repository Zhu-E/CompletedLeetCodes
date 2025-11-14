class Solution {
public:
    int minOperations(int n) {
        vector<bool> digits;
        while(n>0){
            if(n&1){
                digits.push_back(true);
            }
            else{
                digits.push_back(false);
            }
            n/=2;
        }
        int numDigits = digits.size();
        int ans = 0;
        int consecutive = digits[numDigits-1];
        // for(auto i : digits){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        for(int i = numDigits-2; i>=0; --i){
            if(!digits[i]&&digits[i+1]&&consecutive>1){
                digits[i]=true;
                ++ans;
                consecutive=1;
            }
            else if(!digits[i]){
                ans+=consecutive;
                consecutive=0;
            }
            else{
                ++consecutive;
            }
        }
        // cout<<consecutive;
        return ans+min(consecutive, 2);
    }
};
