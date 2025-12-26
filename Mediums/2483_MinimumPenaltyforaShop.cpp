class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix(n+1, 0);
        vector<int> postfix(n+1, 0);
        prefix[0] = 0;
        for(int i = 0; i < n; ++i){
            prefix[i+1]=prefix[i];
            if(customers[i]=='N'){
                prefix[i+1]++;
            }
        }
        postfix[n]=0;
        for(int i = n-1; i >= 0; i --){
            postfix[i]=postfix[i+1];
            if(customers[i]=='Y'){
                postfix[i]++;
            }
        }
        int ans = -1;
        int cur = INT_MAX;
        for(int i = 0; i < n+1; ++i){
            if(prefix[i]+postfix[i]<cur){
                cur = prefix[i]+postfix[i];
                ans = i;
            }
        }
        return ans;
    }
};
