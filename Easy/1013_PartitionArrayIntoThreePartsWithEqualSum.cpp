class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(auto i : arr){
            sum+=i;
        }
        if(sum%3!=0){
            return false;
        }
        int target1=sum/3;
        int target2=target1*2;
        bool t1=false;
        bool t2=false;
        int runningSum=0;
        for(int i = 0; i < n; ++i){
            runningSum+=arr[i];
            if(t1&&runningSum==target2&&i!=n-1){
                t2=true;
            }
            if(runningSum==target1){
                t1=true;
            }
            
        }
        return t1&&t2;
    }
};
