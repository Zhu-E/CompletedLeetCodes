class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> sieve(max(3,n), true);
        sieve[0]=false;
        sieve[1]=false;
        sieve[2]=true;
        for(int i = 3; i < n; ++i){
            for(int j = 2; j <= sqrt(i); ++j){
                if(sieve[j]&&i%j==0){
                    sieve[i]=false;
                }
            }
        }
        long long primeSum = 0;
        long long compositeSum = 0;
        for(int i = 0 ; i < n; ++i){
            if(sieve[i]){
                primeSum+=nums[i];
            }
            else{
                compositeSum+=nums[i];
            }
        }
        return abs(primeSum-compositeSum);

    }
};
