class Solution {
public:
    long long smallestNumber(long long num) {
        bool neg = false;
        if(num<0){
            neg = true;
            num*=-1;
        }
        vector<int> digits;
        while(num>0){
            digits.push_back(num%10);
            num/=10;
        }
        int n = digits.size();
        if(!neg){
            sort(digits.begin(),digits.end());
            for(int i = 0; i < n; ++i){
                if(digits[i]!=0){
                    swap(digits[i], digits[0]);
                    break;
                }
            }
        }
        else{
            sort(digits.begin(),digits.end(), greater<int>());
        }
        long long ans = 0;
        for(int i = 0; i < n; ++i){
            ans*=10;
            ans+=digits[i];
        }
        if(neg){
            return ans*-1;
        }
        else{
            return ans;
        }
    }
};
