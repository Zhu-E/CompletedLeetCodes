class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        queue<bool> ops;
        --k;
        while(k>0){
            if(k&1){
                ops.push(true);
            }
            else{
                ops.push(false);
            }
            k=k>>1;
        }
        int ans = 0;
        int index = 0;
        while(!ops.empty()){
            if(ops.front()==true&&operations[index]==1){
                ans=(ans+1)%26;
            }
            ops.pop();
            ++index;
        }
        return ans+'a';
    }
};
