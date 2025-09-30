class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()!=1){
            int n = nums.size();
            vector<int> nextNums(n-1, 0);
            for(int i = 0; i < n-1; ++i){
                nextNums[i]=(nums[i]+nums[i+1])%10;
            }
            nums=nextNums;
        }
        return nums[0];
    }
    // int triangularSum(vector<int>& nums) {
    //     int n = nums.size();
    //     int ans = 0;
    //     for(int i = 0; i < n; ++i){
    //         // cout<<combinations(n-1,i)<<" "<<i<<" "<<n-1<<endl;
    //         ans+=combinations(n-1,i)*nums[i];
    //         ans%=10;
    //     }
    //     return ans;
    // }
    // long long factorial(int n){
    //     long long ans = 1;
    //     for(int i = 1; i <= n; ++i){
    //         ans*=i;
    //         // ans%=10;
    //     }
    //     return ans;
    // }
    // int combinations(int n, int k){
    //     // cout<<n<<" "<<k<<" "<<factorial(n)<<" "<<factorial(k)<<" "<<factorial(n-k)<<endl;
    //     return (factorial(n)/factorial(k)/factorial(n-k))%10;
    // }
};
